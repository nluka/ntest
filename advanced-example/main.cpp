#include <iostream>

#include "customer.hpp"
#include "../ntest.hpp"

template <typename Ty, size_t Length>
consteval
size_t len(Ty (&)[Length])
{
  return Length;
}

int main()
{
  ntest::init();

  try
  {
    ntest::config::set_max_arr_preview_len(2);
    ntest::config::set_max_str_preview_len(10);

    // int8
    ntest::assert_int8(INT8_MIN, INT8_MIN); // pass
    ntest::assert_int8(INT8_MIN, INT8_MIN + 100); // fail
    ntest::assert_int8(0, 8); // pass
    ntest::assert_int8(0, 8); // fail
    ntest::assert_int8(INT8_MAX, INT8_MAX); // pass
    ntest::assert_int8(INT8_MAX, INT8_MAX - 22); // fail

    // uint8
    ntest::assert_uint8(0, 0); // pass
    ntest::assert_uint8(0, 1); // fail
    ntest::assert_uint8(UINT8_MAX, UINT8_MAX); // pass
    ntest::assert_uint8(UINT8_MAX, UINT8_MAX - 31); // fail

    // int16
    ntest::assert_int16(INT16_MIN, INT16_MIN); // pass
    ntest::assert_int16(INT16_MIN, INT16_MIN + 100); // fail
    ntest::assert_int16(0, 0); // pass
    ntest::assert_int16(0, 42); // fail
    ntest::assert_int16(INT16_MAX, INT16_MAX); // pass
    ntest::assert_int16(INT16_MAX, INT16_MAX - 11); // fail

    // uint16
    ntest::assert_uint16(0, 0); // pass
    ntest::assert_uint16(0, 1); // fail
    ntest::assert_uint16(UINT16_MAX, UINT16_MAX); // pass
    ntest::assert_uint16(UINT16_MAX, UINT16_MAX - 444); // fail

    // int32
    ntest::assert_int32(INT32_MIN, INT32_MIN); // pass
    ntest::assert_int32(INT32_MIN, INT32_MIN + 100); // fail
    ntest::assert_int32(0, 0); // pass
    ntest::assert_int32(0, 42); // fail
    ntest::assert_int32(INT32_MAX, INT32_MAX); // pass
    ntest::assert_int32(INT32_MAX, INT32_MAX - 1); // fail

    // uint32
    ntest::assert_uint32(0, 0); // pass
    ntest::assert_uint32(0, 1); // fail
    ntest::assert_uint32(UINT32_MAX, UINT32_MAX); // pass
    ntest::assert_uint32(UINT32_MAX, UINT32_MAX - 444); // fail

    // int64
    ntest::assert_int64(INT64_MIN, INT64_MIN); // pass
    ntest::assert_int64(INT64_MIN, INT64_MIN + 100); // fail
    ntest::assert_int64(0, 0); // pass
    ntest::assert_int64(0, 42); // fail
    ntest::assert_int64(INT64_MAX, INT64_MAX); // pass
    ntest::assert_int64(INT64_MAX, INT64_MAX - 1001); // fail

    // uint64_t
    ntest::assert_uint64(0, 0); // pass
    ntest::assert_uint64(0, 1); // fail
    ntest::assert_uint64(UINT64_MAX, UINT64_MAX); // pass
    ntest::assert_uint64(UINT64_MAX, UINT64_MAX - 42); // fail

    // char*
    {
      char const *const hello_world = "Hello\nworld!";
      char const *const alphabet = "abcdefghijklmnopqrstuvwxyz";

      ntest::assert_cstr(hello_world, "hello world!"); // fail
      ntest::assert_cstr(hello_world, "Hello world"); // fail
      ntest::assert_cstr(hello_world, hello_world); // pass
      ntest::assert_cstr(hello_world, alphabet); // fail
      ntest::assert_cstr(alphabet, alphabet); // pass
    }

    // std::string
    {
      std::string const expected = "Testing code is important.";

      ntest::assert_stdstr(expected, "Testing code is not important."); // fail
      ntest::assert_stdstr(expected, "What is ntesting?"); // fail
      ntest::assert_stdstr(expected, expected); // pass
    }

    // std::string with NULs
    {
      std::stringstream ss{};
      ss << "Testing" << '\0' << "code" << '\0' << "is" << '\0' << "important.";

      ntest::assert_stdstr("Testing code is important.", ss.str()); // fail
      ntest::assert_stdstr(ss.str(), ss.str()); // pass
    }

    // int []
    {
      int const expected[] { 0, 1, 2, 3 };
      int const a[]        { 1, 2, 3, 4 };
      int const b[]        { 0, 0, 0, 0 };

      ntest::assert_arr(expected, len(expected), a, len(a)); // fail
      ntest::assert_arr(expected, len(expected), b, len(b)); // fail
      ntest::assert_arr(expected, len(expected), expected, len(expected)); // pass
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

      ntest::assert_arr(expected, len(expected), a, len(a)); // fail
      ntest::assert_arr(expected, len(expected), b, len(b)); // fail
      ntest::assert_arr(expected, len(expected), c, len(c)); // fail
      ntest::assert_arr(expected, len(expected), expected, len(expected)); // pass
    }

    // std::vector<int>
    {
      std::vector<int> const expected { 0, 1, 2, 3 };
      std::vector<int> const a        { 1, 2, 3, 4 };
      std::vector<int> const b        { 0, 0, 0, 0 };

      ntest::assert_stdvec(expected, a); // fail
      ntest::assert_stdvec(expected, b); // fail
      ntest::assert_stdvec(expected, expected); // pass
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

      ntest::assert_stdvec(expected, a); // fail
      ntest::assert_stdvec(expected, b); // fail
      ntest::assert_stdvec(expected, c); // fail
      ntest::assert_stdvec(expected, expected); // pass
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
        "ntesting?",
      };

      ntest::assert_stdvec(expected, a); // fail
      ntest::assert_stdvec(expected, b); // fail
      ntest::assert_stdvec(expected, expected); // pass
    }

    // std::array<int>
    {
      std::array<int, 4> const expected { 0, 1, 2, 3 };
      std::array<int, 4> const a        { 1, 2, 3, 4 };
      std::array<int, 4> const b        { 0, 0, 0, 0 };

      ntest::assert_stdarr(expected, a); // fail
      ntest::assert_stdarr(expected, b); // fail
      ntest::assert_stdarr(expected, expected); // pass
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

      ntest::assert_stdarr(expected, a); // fail
      ntest::assert_stdarr(expected, b); // fail
      ntest::assert_stdarr(expected, expected); // pass
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
        "ntesting?",
      };

      ntest::assert_stdarr(expected, a); // fail
      ntest::assert_stdarr(expected, b); // fail
      ntest::assert_stdarr(expected, expected); // pass
    }

    // text files
    ntest::assert_text_file("./files/expected.txt", "./files/a.txt");
    ntest::assert_text_file("./files/expected.txt", "./files/b.txt");
    ntest::assert_text_file("./files/expected.txt", "./files/expected.txt");
    ntest::assert_text_file("./files/does_not_exist.txt", "./files/a.txt");
    ntest::assert_text_file("./files/expected.txt", "./files/does_not_exist.txt");

    // binary files
    ntest::assert_binary_file("./files/expected.bin", "./files/a.bin");
    ntest::assert_binary_file("./files/expected.bin", "./files/b.bin");
    ntest::assert_binary_file("./files/expected.bin", "./files/expected.bin");
    ntest::assert_binary_file("./files/does_not_exist.bin", "./files/a.bin");
    ntest::assert_binary_file("./files/expected.bin", "./files/does_not_exist.bin");

    try {
      int expected[] = { 1, 2, 3 };
      int *actual = nullptr;
      // this should throw because we said actual has 3 elems when it's really a nullptr
      ntest::assert_arr(expected, 3, actual, 3);
      std::cerr << "failed to catch user error!\n";
    } catch (std::runtime_error const &err) {
      std::cout << "successfully caught user error: " << err.what() << '\n';
    }

    ntest::generate_report("example");
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
