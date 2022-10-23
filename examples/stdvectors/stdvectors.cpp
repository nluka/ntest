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

    // std::vector<int>
    {
      std::vector<int> expected { 0, 1, 2, 3 };
      std::vector<int> a { 1, 2, 3, 4 };
      std::vector<int> b { 0, 0, 0, 0 };

      test::assert_stdvec(expected, a);
      test::assert_stdvec(expected, b);
      test::assert_stdvec(expected, expected);
    }

    // std::vector<customer>
    {
      std::vector<customer> expected {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
      };

      std::vector<customer> a {
        {"Alice", "Willians", 22},
        {"Will", "Robertson", 54},
      };

      std::vector<customer> b {
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"Alice", "Smith", 22},
      };

      std::vector<customer> c {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"John", "Miller", 67},
      };

      test::assert_stdvec(expected, a);
      test::assert_stdvec(expected, b);
      test::assert_stdvec(expected, c);
      test::assert_stdvec(expected, expected);
    }

    // std::vector<std::string>
    {
      std::vector<std::string> expected {
        "Testing",
        "code",
        "is",
        "important!",
      };

      std::vector<std::string> a {
        "Testing",
        "code",
        "is",
        "not",
        "important.",
      };

      std::vector<std::string> b {
        "What",
        "is",
        "testing?",
      };

      test::assert_stdvec(expected, a);
      test::assert_stdvec(expected, b);
      test::assert_stdvec(expected, expected);
    }

    test::generate_report("stdvectors");
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
