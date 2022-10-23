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

    // std::array<int>
    {
      std::array<int, 4> expected { 0, 1, 2, 3 };
      std::array<int, 4> a { 1, 2, 3, 4 };
      std::array<int, 4> b { 0, 0, 0, 0 };

      test::assert_stdarr(expected, a);
      test::assert_stdarr(expected, b);
      test::assert_stdarr(expected, expected);
    }

    // std::array<customer>
    {
      std::array<customer, 3> expected {
        customer("Alice", "Smith", 22),
        customer("Joe", "Schmoe", 100),
        customer("Rob", "Robertson", 53),
      };

      std::array<customer, 3> a {
        customer("Smith", "Alice", 22),
        customer("Rob", "Robertson", 53),
        customer("Joe", "Schmoe", 100),
      };

      std::array<customer, 3> b {
        customer("Alice", "Smith", 22),
        customer("Joe", "Schmoe", 77),
        customer("Rob", "Robertson", 40),
      };

      test::assert_stdarr(expected, a);
      test::assert_stdarr(expected, b);
      test::assert_stdarr(expected, expected);
    }

    // std::array<std::string>
    {
      std::array<std::string, 4> expected {
        "Testing",
        "code",
        "is",
        "important!",
      };

      std::array<std::string, 4> a {
        "Testing",
        "code",
        "aint",
        "important.",
      };

      std::array<std::string, 4> b {
        "What",
        "is",
        "testing?",
      };

      test::assert_stdarr(expected, a);
      test::assert_stdarr(expected, b);
      test::assert_stdarr(expected, expected);
    }

    test::generate_report("stdarrays");
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
