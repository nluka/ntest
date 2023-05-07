#include <cassert>
#include <iostream>

#include "customer.hpp"
#include "custom_exception.hpp"
#include "timer.hpp"
#include "../ntest.hpp"

template <typename Ty, size_t Length>
consteval
size_t len(Ty (&)[Length])
{
  return Length;
}

int main()
{
  ntest::config::set_show_column_numbers(false);

  size_t observed_pass_cnt = 0, observed_fail_cnt = 0;

  auto const ensure_passed = [&observed_pass_cnt](
    // not actually used, but for code annotation:
    [[maybe_unused]] char const *const desc = nullptr,
    std::source_location const loc = std::source_location::current()
  ) {
    ++observed_pass_cnt;
    size_t const ntest_pass_cnt = ntest::pass_count();
    if (ntest_pass_cnt != observed_pass_cnt) {
      std::cerr << "ERROR: incorrect assertion outcome (wanted pass, got fail) on line " << loc.line() << '\n';
      ntest::generate_report("validation");
      std::exit(1);
    }
  };

  auto const ensure_failed = [&observed_fail_cnt](
    // not actually used, but for code annotation:
    [[maybe_unused]] char const *const desc = nullptr,
    std::source_location const loc = std::source_location::current()
  ) {
    ++observed_fail_cnt;
    size_t const ntest_fail_cnt = ntest::fail_count();
    if (ntest_fail_cnt != observed_fail_cnt) {
      std::cerr << "ERROR: incorrect assertion outcome (wanted fail, got pass) on line " << loc.line() << '\n';
      ntest::generate_report("validation");
      std::exit(1);
    }
  };

  try
  {
    timer::scoped<timer::unit::MILLISECONDS> timer("execution", std::cout);

    ntest::init();
    ntest::config::set_max_arr_preview_len(2);
    ntest::config::set_max_str_preview_len(15);

    // bool
    ntest::assert_bool(true, true); ensure_passed();
    ntest::assert_bool(true, false); ensure_failed();

    // int8
    ntest::assert_int8(INT8_MIN, INT8_MIN); ensure_passed();
    ntest::assert_int8(INT8_MIN, INT8_MIN + 100); ensure_failed();
    ntest::assert_int8(0, 0); ensure_passed();
    ntest::assert_int8(0, 8); ensure_failed();
    ntest::assert_int8(INT8_MAX, INT8_MAX); ensure_passed();
    ntest::assert_int8(INT8_MAX, INT8_MAX - 22); ensure_failed();

    // uint8
    ntest::assert_uint8(0, 0); ensure_passed();
    ntest::assert_uint8(0, 1); ensure_failed();
    ntest::assert_uint8(UINT8_MAX, UINT8_MAX); ensure_passed();
    ntest::assert_uint8(UINT8_MAX, UINT8_MAX - 31); ensure_failed();

    // int16
    ntest::assert_int16(INT16_MIN, INT16_MIN); ensure_passed();
    ntest::assert_int16(INT16_MIN, INT16_MIN + 100); ensure_failed();
    ntest::assert_int16(0, 0); ensure_passed();
    ntest::assert_int16(0, 42); ensure_failed();
    ntest::assert_int16(INT16_MAX, INT16_MAX); ensure_passed();
    ntest::assert_int16(INT16_MAX, INT16_MAX - 11); ensure_failed();

    // uint16
    ntest::assert_uint16(0, 0); ensure_passed();
    ntest::assert_uint16(0, 1); ensure_failed();
    ntest::assert_uint16(UINT16_MAX, UINT16_MAX); ensure_passed();
    ntest::assert_uint16(UINT16_MAX, UINT16_MAX - 444); ensure_failed();

    // int32
    ntest::assert_int32(INT32_MIN, INT32_MIN); ensure_passed();
    ntest::assert_int32(INT32_MIN, INT32_MIN + 100); ensure_failed();
    ntest::assert_int32(0, 0); ensure_passed();
    ntest::assert_int32(0, 42); ensure_failed();
    ntest::assert_int32(INT32_MAX, INT32_MAX); ensure_passed();
    ntest::assert_int32(INT32_MAX, INT32_MAX - 1); ensure_failed();

    // uint32
    ntest::assert_uint32(0, 0); ensure_passed();
    ntest::assert_uint32(0, 1); ensure_failed();
    ntest::assert_uint32(UINT32_MAX, UINT32_MAX); ensure_passed();
    ntest::assert_uint32(UINT32_MAX, UINT32_MAX - 444); ensure_failed();

    // int64
    ntest::assert_int64(INT64_MIN, INT64_MIN); ensure_passed();
    ntest::assert_int64(INT64_MIN, INT64_MIN + 100); ensure_failed();
    ntest::assert_int64(0, 0); ensure_passed();
    ntest::assert_int64(0, 42); ensure_failed();
    ntest::assert_int64(INT64_MAX, INT64_MAX); ensure_passed();
    ntest::assert_int64(INT64_MAX, INT64_MAX - 1001); ensure_failed();

    // uint64_t
    ntest::assert_uint64(0, 0); ensure_passed();
    ntest::assert_uint64(0, 1); ensure_failed();
    ntest::assert_uint64(UINT64_MAX, UINT64_MAX); ensure_passed();
    ntest::assert_uint64(UINT64_MAX, UINT64_MAX - 42); ensure_failed();

    // char*
    {
      char const *const hello_world = "Hello\nworld!";
      char const *const alphabet = "abcdefghijklmnopqrstuvwxyz";

      ntest::assert_cstr(hello_world, "hello\nworld!"); ensure_failed();
      ntest::assert_cstr(hello_world, "Hello world"); ensure_failed();
      ntest::assert_cstr(hello_world, hello_world); ensure_passed();
      ntest::assert_cstr(hello_world, alphabet); ensure_failed();
      ntest::assert_cstr(alphabet, alphabet); ensure_passed();
    }

    // std::string
    {
      std::string const expected = "Testing code is important.";

      ntest::assert_stdstr(expected, "Testing code is not important."); ensure_failed();
      ntest::assert_stdstr(expected, "What is testing?"); ensure_failed();
      ntest::assert_stdstr(expected, expected); ensure_passed();
    }

    // std::string with NULs
    {
      std::stringstream ss{};
      ss << "Testing" << '\0' << "code" << '\0' << "is" << '\0' << "important.";

      ntest::assert_stdstr("Testing code is important.", ss.str()); ensure_failed();
      ntest::assert_stdstr(ss.str(), ss.str()); ensure_passed();
    }

    // strings with backticks
    {
      char const *const str = "`Backtick`";
      ntest::assert_cstr(str, str); ensure_passed();
      ntest::assert_stdstr(str, str); ensure_passed();
      ntest::assert_cstr(str, "nonsense"); ensure_failed();
      ntest::assert_stdstr(str, "nonsense"); ensure_failed();
    }
    {
      std::vector<std::string> const a { "`Backtick`" };
      ntest::assert_stdvec(a, a); ensure_passed();
      ntest::assert_stdvec(a, {}); ensure_failed();
    }

    // int []
    {
      int const expected[] { 0, 1, 2, 3 };
      int const a[]        { 1, 2, 3, 4 };
      int const b[]        { 0, 0, 0, 0 };

      ntest::assert_arr(expected, len(expected), a, len(a)); ensure_failed();
      ntest::assert_arr(expected, len(expected), b, len(b)); ensure_failed();
      ntest::assert_arr(expected, len(expected), expected, len(expected)); ensure_passed();
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

      ntest::assert_arr(expected, len(expected), a, len(a)); ensure_failed();
      ntest::assert_arr(expected, len(expected), b, len(b)); ensure_failed();
      ntest::assert_arr(expected, len(expected), c, len(c)); ensure_failed();
      ntest::assert_arr(expected, len(expected), expected, len(expected)); ensure_passed();
    }

    // std::vector<int>
    {
      std::vector<int> const expected { 0, 1, 2, 3 };
      std::vector<int> const a        { 1, 2, 3, 4 };
      std::vector<int> const b        { 0, 0, 0, 0 };

      ntest::assert_stdvec(expected, a); ensure_failed();
      ntest::assert_stdvec(expected, b); ensure_failed();
      ntest::assert_stdvec(expected, expected); ensure_passed();
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

      ntest::assert_stdvec(expected, a); ensure_failed();
      ntest::assert_stdvec(expected, b); ensure_failed();
      ntest::assert_stdvec(expected, c); ensure_failed();
      ntest::assert_stdvec(expected, expected); ensure_passed();
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

      ntest::assert_stdvec(expected, a); ensure_failed();
      ntest::assert_stdvec(expected, b); ensure_failed();
      ntest::assert_stdvec(expected, expected); ensure_passed();

      std::vector<std::string> const c {
        "Testing\n",
        "code\n",
        "is\n",
        "important!\n",
      };
      std::vector<std::string> const d {
        "`Testing`",
        "`code`",
        "`is`",
        "`important!`",
      };

      ntest::assert_stdvec(c, c); ensure_passed(); // check preview has \n escaped
      ntest::assert_stdvec(expected, c); ensure_failed(); // check .actual has \n escaped
      ntest::assert_stdvec(expected, d); ensure_failed(); // check .actual has does not escape `
    }

    // std::array<int>
    {
      std::array<int, 4> const expected { 0, 1, 2, 3 };
      std::array<int, 4> const a        { 1, 2, 3, 4 };
      std::array<int, 4> const b        { 0, 0, 0, 0 };

      ntest::assert_stdarr(expected, a); ensure_failed();
      ntest::assert_stdarr(expected, b); ensure_failed();
      ntest::assert_stdarr(expected, expected); ensure_passed();
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

      ntest::assert_stdarr(expected, a); ensure_failed();
      ntest::assert_stdarr(expected, b); ensure_failed();
      ntest::assert_stdarr(expected, expected); ensure_passed();
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

      ntest::assert_stdarr(expected, a); ensure_failed();
      ntest::assert_stdarr(expected, b); ensure_failed();
      ntest::assert_stdarr(expected, expected); ensure_passed();
    }

    // text files
    ntest::assert_text_file("./files/expected.txt", "./files/a.txt"); ensure_failed();
    ntest::assert_text_file("./files/expected.txt", "./files/b.txt"); ensure_failed();
    ntest::assert_text_file("./files/expected.txt", "./files/expected.txt"); ensure_passed();
    ntest::assert_text_file("./files/does_not_exist.txt", "./files/a.txt"); ensure_failed();
    ntest::assert_text_file("./files/expected.txt", "./files/does_not_exist.txt"); ensure_failed();

    // binary files
    ntest::assert_binary_file("./files/expected.bin", "./files/a.bin"); ensure_failed();
    ntest::assert_binary_file("./files/expected.bin", "./files/b.bin"); ensure_failed();
    ntest::assert_binary_file("./files/expected.bin", "./files/expected.bin"); ensure_passed();
    ntest::assert_binary_file("./files/does_not_exist.bin", "./files/a.bin"); ensure_failed();
    ntest::assert_binary_file("./files/expected.bin", "./files/does_not_exist.bin"); ensure_failed();

    // exceptions
    {
      std::string what_str;

      what_str = ntest::assert_throws<std::runtime_error>([]() {
        throw std::runtime_error(std::string("some explanatory string"));
      });
      assert(!what_str.empty());
      ensure_passed("because correct exception type was thrown");
      ntest::assert_cstr("some explanatory string", what_str.c_str()); ensure_passed();
      ntest::assert_cstr("some other explanatory string", what_str.c_str()); ensure_failed();

      what_str = ntest::assert_throws<std::runtime_error>([]() {
        throw std::exception();
      });
      assert(what_str.empty());
      ensure_failed("because wrong exception type was thrown");

      what_str = ntest::assert_throws<std::runtime_error>([]() {
        int a = 10, b = 20;
        [[maybe_unused]] int c = a + b;
      });
      assert(what_str.empty());
      ensure_failed("because nothing was thrown");

      what_str = ntest::assert_throws<custom_exception>([]() {
        throw custom_exception();
      });
      ensure_passed("because correct exception type was thrown");
      ntest::assert_cstr("Something bad happened", what_str.c_str()); ensure_passed();

      what_str = ntest::assert_throws<custom_exception>([]() {
        int a = 10, b = 20;
        [[maybe_unused]] int c = a + b;
      });
      assert(what_str.empty());
      ensure_failed("because nothing was thrown");

      what_str = ntest::assert_throws<custom_exception>([]() {
        throw std::exception();
      });
      assert(what_str.empty());
      ensure_failed("because wrong exception type was thrown");
    }

    try
    {
      int expected[] = { 1, 2, 3 };
      int *actual = nullptr;
      // this should throw because we said `actual` has 3 elems
      // when it's really a nullptr:
      ntest::assert_arr(expected, 3, actual, 3);
      std::cerr << "failed to catch user error!\n";
    }
    catch (std::runtime_error const &err)
    {
      std::cout << "successfully caught user error: " << err.what() << '\n';
    }

    // verify pass/fail counts:
    {
      size_t const
        expected_pass_cnt = observed_pass_cnt,
        expected_fail_cnt = observed_fail_cnt,
        actual_pass_cnt = ntest::pass_count(),
        actual_fail_cnt = ntest::fail_count()
      ;
      bool const success =
        (actual_pass_cnt == expected_pass_cnt) &&
        (actual_fail_cnt == expected_fail_cnt)
      ;
      std::cout
        << (success ? "SUCCESS" : "FAIL") << "! "
        << "expected pass/fail = " << expected_pass_cnt << '/' << expected_fail_cnt
        << ", observed " << actual_pass_cnt << '/' << actual_fail_cnt << '\n';
      ;
    }
    ntest::generate_report("validation");
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

  return 0;
}
