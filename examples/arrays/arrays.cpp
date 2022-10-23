#include <iostream>

#include "../customer.hpp"
#include "../../src/test.hpp"

template <typename ElemTy, size_t Length>
constexpr
size_t lengthof(ElemTy (&)[Length])
{
  return Length;
}

int main()
{
  try
  {
    test::config::set_max_arr_preview_len(2);

    // int []
    {
      int expected[] { 0, 1, 2, 3 };
      int a[] { 1, 2, 3, 4 };
      int b[] { 0, 0, 0, 0 };

      test::assert_arr(expected, lengthof(expected),
        a, lengthof(a));

      test::assert_arr(expected, lengthof(expected),
        b, lengthof(b));

      test::assert_arr(expected, lengthof(expected),
        expected, lengthof(expected));
    }

    // customer []
    {
      customer expected[] {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
      };

      customer a[] {
        {"Alice", "Willians", 22},
        {"Will", "Robertson", 54},
      };

      customer b[] {
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"Alice", "Smith", 22},
      };

      customer c[] {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"John", "Miller", 67},
      };

      test::assert_arr(expected, lengthof(expected),
        a, lengthof(a));

      test::assert_arr(expected, lengthof(expected),
        b, lengthof(b));

      test::assert_arr(expected, lengthof(expected),
        c, lengthof(c));

      test::assert_arr(expected, lengthof(expected),
        expected, lengthof(expected));
    }

    test::generate_report("arrays");
  }
  catch (std::runtime_error const &err)
  {
    std::cerr << "fatal: " << err.what() << '\n';
    return 1;
  }
  catch (...)
  {
    std::cerr << "fatal: unknown error\n";
    return 2;
  }

  std::cout << "success!\n";
  return 0;
}
