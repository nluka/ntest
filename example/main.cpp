#include <iostream>

#include "customer.hpp"
#include "../ntest.hpp"

template <typename Ty, size_t Length>
constexpr
size_t len(Ty (&)[Length])
{
  return Length;
}

int main()
{
  try
  {
    test::config::set_max_arr_preview_len(2);
    test::config::set_max_str_preview_len(10);

    // int8
    test::assert_int8(INT8_MIN, INT8_MIN); // pass
    test::assert_int8(INT8_MIN, INT8_MIN + 100); // fail
    test::assert_int8(0, 8); // pass
    test::assert_int8(0, 8); // fail
    test::assert_int8(INT8_MAX, INT8_MAX); // pass
    test::assert_int8(INT8_MAX, INT8_MAX - 22); // fail

    // uint8
    test::assert_uint8(0, 0); // pass
    test::assert_uint8(0, 1); // fail
    test::assert_uint8(UINT8_MAX, UINT8_MAX); // pass
    test::assert_uint8(UINT8_MAX, UINT8_MAX - 31); // fail

    // int16
    test::assert_int16(INT16_MIN, INT16_MIN); // pass
    test::assert_int16(INT16_MIN, INT16_MIN + 100); // fail
    test::assert_int16(0, 0); // pass
    test::assert_int16(0, 42); // fail
    test::assert_int16(INT16_MAX, INT16_MAX); // pass
    test::assert_int16(INT16_MAX, INT16_MAX - 11); // fail

    // uint16
    test::assert_uint16(0, 0); // pass
    test::assert_uint16(0, 1); // fail
    test::assert_uint16(UINT16_MAX, UINT16_MAX); // pass
    test::assert_uint16(UINT16_MAX, UINT16_MAX - 444); // fail

    // int32
    test::assert_int32(INT32_MIN, INT32_MIN); // pass
    test::assert_int32(INT32_MIN, INT32_MIN + 100); // fail
    test::assert_int32(0, 0); // pass
    test::assert_int32(0, 42); // fail
    test::assert_int32(INT32_MAX, INT32_MAX); // pass
    test::assert_int32(INT32_MAX, INT32_MAX - 1); // fail

    // uint32
    test::assert_uint32(0, 0); // pass
    test::assert_uint32(0, 1); // fail
    test::assert_uint32(UINT32_MAX, UINT32_MAX); // pass
    test::assert_uint32(UINT32_MAX, UINT32_MAX - 444); // fail

    // int64
    test::assert_int64(INT64_MIN, INT64_MIN); // pass
    test::assert_int64(INT64_MIN, INT64_MIN + 100); // fail
    test::assert_int64(0, 0); // pass
    test::assert_int64(0, 42); // fail
    test::assert_int64(INT64_MAX, INT64_MAX); // pass
    test::assert_int64(INT64_MAX, INT64_MAX - 1001); // fail

    // uint64_t
    test::assert_uint64(0, 0); // pass
    test::assert_uint64(0, 1); // fail
    test::assert_uint64(UINT64_MAX, UINT64_MAX); // pass
    test::assert_uint64(UINT64_MAX, UINT64_MAX - 42); // fail

    // char*
    {
      char const *const hello_world = "Hello\nworld!";
      char const *const alphabet = "abcdefghijklmnopqrstuvwxyz";

      test::assert_cstr(hello_world, "hello world!"); // fail
      test::assert_cstr(hello_world, "Hello world"); // fail
      test::assert_cstr(hello_world, hello_world); // pass
      test::assert_cstr(hello_world, alphabet); // fail
      test::assert_cstr(alphabet, alphabet); // pass
    }

    // std::string
    {
      std::string const expected = "Testing code is important.";

      test::assert_stdstr(expected, "Testing code is not important."); // fail
      test::assert_stdstr(expected, "What is testing?"); // fail
      test::assert_stdstr(expected, expected); // pass
    }

    // std::string with NULs
    {
      std::stringstream ss{};
      ss << "Testing" << '\0' << "code" << '\0' << "is" << '\0' << "important.";

      test::assert_stdstr("Testing code is important.", ss.str()); // fail
      test::assert_stdstr(ss.str(), ss.str()); // pass
    }

    // int []
    {
      int const expected[] { 0, 1, 2, 3 };
      int const a[]        { 1, 2, 3, 4 };
      int const b[]        { 0, 0, 0, 0 };

      test::assert_arr(expected, len(expected), a, len(a)); // fail
      test::assert_arr(expected, len(expected), b, len(b)); // fail
      test::assert_arr(expected, len(expected), expected, len(expected)); // pass
    }

    // customer []
    {
      customer const expected[] {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
      };
      customer const a[] {
        {"Alice", "Willians", 22},
        {"Will", "Robertson", 54},
      };
      customer const b[] {
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"Alice", "Smith", 22},
      };
      customer const c[] {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"John", "Miller", 67},
      };

      test::assert_arr(expected, len(expected), a, len(a)); // fail
      test::assert_arr(expected, len(expected), b, len(b)); // fail
      test::assert_arr(expected, len(expected), c, len(c)); // fail
      test::assert_arr(expected, len(expected), expected, len(expected)); // pass
    }

    // std::vector<int>
    {
      std::vector<int> const expected { 0, 1, 2, 3 };
      std::vector<int> const a        { 1, 2, 3, 4 };
      std::vector<int> const b        { 0, 0, 0, 0 };

      test::assert_stdvec(expected, a); // fail
      test::assert_stdvec(expected, b); // fail
      test::assert_stdvec(expected, expected); // pass
    }

    // std::vector<customer>
    {
      std::vector<customer> const expected {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
      };
      std::vector<customer> const a {
        {"Alice", "Willians", 22},
        {"Will", "Robertson", 54},
      };
      std::vector<customer> const b {
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"Alice", "Smith", 22},
      };
      std::vector<customer> const c {
        {"Alice", "Smith", 22},
        {"Joe", "Schmoe", 100},
        {"Rob", "Robertson", 53},
        {"John", "Miller", 67},
      };

      test::assert_stdvec(expected, a); // fail
      test::assert_stdvec(expected, b); // fail
      test::assert_stdvec(expected, c); // fail
      test::assert_stdvec(expected, expected); // pass
    }

    // std::vector<std::string>
    {
      std::vector<std::string> const expected {
        "Testing",
        "code",
        "is",
        "important!",
      };
      std::vector<std::string> const a {
        "Testing",
        "code",
        "is",
        "not",
        "important.",
      };
      std::vector<std::string> const b {
        "What",
        "is",
        "testing?",
      };

      test::assert_stdvec(expected, a); // fail
      test::assert_stdvec(expected, b); // fail
      test::assert_stdvec(expected, expected); // pass
    }

    // std::array<int>
    {
      std::array<int, 4> const expected { 0, 1, 2, 3 };
      std::array<int, 4> const a        { 1, 2, 3, 4 };
      std::array<int, 4> const b        { 0, 0, 0, 0 };

      test::assert_stdarr(expected, a); // fail
      test::assert_stdarr(expected, b); // fail
      test::assert_stdarr(expected, expected); // pass
    }

    // std::array<customer>
    {
      std::array<customer, 3> const expected {
        customer("Alice", "Smith", 22),
        customer("Joe", "Schmoe", 100),
        customer("Rob", "Robertson", 53),
      };
      std::array<customer, 3> const a {
        customer("Smith", "Alice", 22),
        customer("Rob", "Robertson", 53),
        customer("Joe", "Schmoe", 100),
      };
      std::array<customer, 3> const b {
        customer("Alice", "Smith", 22),
        customer("Joe", "Schmoe", 77),
        customer("Rob", "Robertson", 40),
      };

      test::assert_stdarr(expected, a); // fail
      test::assert_stdarr(expected, b); // fail
      test::assert_stdarr(expected, expected); // pass
    }

    // std::array<std::string>
    {
      std::array<std::string, 4> const expected {
        "Testing",
        "code",
        "is",
        "important!",
      };
      std::array<std::string, 4> const a {
        "Testing",
        "code",
        "aint",
        "important.",
      };
      std::array<std::string, 4> const b {
        "What",
        "is",
        "testing?",
      };

      test::assert_stdarr(expected, a); // fail
      test::assert_stdarr(expected, b); // fail
      test::assert_stdarr(expected, expected); // pass
    }

    // text files
    test::assert_text_file("./files/expected.txt", "./files/a.txt");
    test::assert_text_file("./files/expected.txt", "./files/b.txt");
    test::assert_text_file("./files/expected.txt", "./files/expected.txt");
    test::assert_text_file("./files/does_not_exist.txt", "./files/a.txt");
    test::assert_text_file("./files/expected.txt", "./files/does_not_exist.txt");

    // binary files

    test::generate_report("example");
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
