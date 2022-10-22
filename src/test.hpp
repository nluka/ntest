#ifndef NLUKA_TEST_HPP
#define NLUKA_TEST_HPP

#include <concepts>
#include <source_location>
#include <string>
#include <type_traits>

namespace test {

namespace config {

  void set_output_path(char const *);

  void set_max_str_preview_len(size_t);

} // namespace config

namespace internal {

  size_t max_str_preview_len();

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
concept primitive = std::integral<Ty> || std::floating_point<Ty>;

// template <typename Ty>
// requires primitive<Ty>
// void assert_carr(
//   std::string const &expected, std::string const &actual,
//   std::source_location loc = std::source_location::current())
// {

// }

// TODO:
// assert_stdarr
// assert_stdvec
// ...

void generate_report(char const *name);

} // namespace test

#endif // NLUKA_TEST_HPP
