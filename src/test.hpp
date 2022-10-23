#ifndef NLUKA_TEST_HPP
#define NLUKA_TEST_HPP

#include <concepts>
#include <fstream>
#include <functional>
#include <source_location>
#include <sstream>
#include <string>
#include <type_traits>

namespace test {

namespace config {

  void set_output_path(char const *);

  void set_max_str_preview_len(size_t);

  void set_max_arr_preview_len(size_t);

} // namespace config

namespace internal {

  size_t max_str_preview_len();

  size_t max_arr_preview_len();

  std::string generate_file_pathname(
    std::source_location const &, char const *extension);

  void throw_if_file_not_open(FILE const *, char const *pathname);

  struct assertion
  {
    std::string serialized_vals;
    std::source_location loc;
  };

  void emplace_assertion_passed_primitive(
    std::stringstream &&, std::source_location const &);

  void emplace_assertion_failed_primitive(
    std::stringstream &&, std::source_location const &);

  void emplace_assertion_passed_container(
    std::stringstream &&, std::source_location const &);

  void emplace_assertion_failed_container(
    std::stringstream &&, std::source_location const &);

} // namespace internal

void assert_int8(
  int8_t expected, int8_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_uint8(
  uint8_t expected, uint8_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_int16(
  int16_t expected, int16_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_uint16(
  uint16_t expected, uint16_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_int32(
  int32_t expected, int32_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_uint32(
  uint32_t expected, uint32_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_int64(
  int64_t expected, int64_t actual,
  std::source_location loc = std::source_location::current()
);

void assert_uint64(
  uint64_t expected, uint64_t actual,
  std::source_location loc = std::source_location::current()
);

struct str_opts
{
  bool escape_special_chars;
};

void assert_cstr(
  char const *expected, char const *actual,
  str_opts const &options = { true },
  std::source_location loc = std::source_location::current()
);

void assert_cstr(
  char const *expected, size_t expected_len,
  char const *actual, size_t actual_len,
  str_opts const &options = { true },
  std::source_location loc = std::source_location::current()
);

void assert_stdstr(
  std::string const &expected, std::string const &actual,
  str_opts const &options = { true },
  std::source_location loc = std::source_location::current()
);

template <typename Ty>
void serialize_arr_preview(
  Ty const *const arr, size_t const size, std::stringstream &ss)
{
  ss << "sz=" << size;

  if (size == 0)
    return;

  ss << " __[__ ` ";

  size_t const max_len = std::min(size, test::internal::max_arr_preview_len());
  for (size_t i = 0; i < max_len; ++i)
    ss << arr[i] << ' ';

  ss << "` ";

  if (size > max_len)
    ss << "*... " << (size - max_len) << " more* ";

  ss << "__]__";
}

template <typename Ty>
concept primitive = std::integral<Ty> || std::floating_point<Ty>;

template <typename Ty>
concept comparable_neq = requires(Ty a, Ty b) { a != b; };

template <typename Ty>
concept printable = requires(std::ostream os, Ty obj) { os << obj; };

template <typename Ty>
requires comparable_neq<Ty> && printable<Ty>
void assert_arr(
  Ty const *const expected, size_t const expected_size,
  Ty const *const actual, size_t const actual_size,
  std::source_location const loc = std::source_location::current())
{
  bool passed = true;
  if (actual_size != expected_size)
    passed = false;
  else
    for (size_t i = 0; i < expected_size; ++i)
      if (actual[i] != expected[i])
      {
        passed = false;
        break;
      }

  std::stringstream serialized_vals{};
  serialized_vals << typeid(Ty).name() << " [] | ";
  if (passed)
  {
    serialize_arr_preview(expected, expected_size, serialized_vals);
    test::internal::emplace_assertion_passed_container(
      std::move(serialized_vals), loc);
  }
  else // failed
  {
    std::string const
      expected_pathname = internal::generate_file_pathname(loc, "expected"),
      actual_pathname = internal::generate_file_pathname(loc, "actual");

    auto const write_file = [](std::string const &pathname,
      Ty const *const arr, size_t const size)
    {
      FILE *const file = fopen(pathname.c_str(), "w");
      test::internal::throw_if_file_not_open(file, pathname.c_str());

      std::ofstream out(file);

      for (size_t i = 0; i < size; ++i)
        out << arr[i] << '\n';
    };

    write_file(expected_pathname, expected, expected_size);
    write_file(actual_pathname, actual, actual_size);

    serialized_vals
      << '[' << expected_pathname << "](" << expected_pathname
      << ") | [" << actual_pathname << "](" << actual_pathname << ')';

    test::internal::emplace_assertion_failed_container(
      std::move(serialized_vals), loc);
  }
}

// TODO:
// assert_stdarr
// assert_stdvec
// ...

void generate_report(char const *name);

} // namespace test

#endif // NLUKA_TEST_HPP
