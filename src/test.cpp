#include <chrono>
#include <cstdio>
#include <filesystem>
#include <sstream>
#include <string>
#include <vector>

#include "test.hpp"

namespace fs = std::filesystem;
using std::string;
using std::vector;
using std::source_location;
using std::stringstream;
using std::runtime_error;

struct assertion
{
  string serialized_vals;
  source_location loc;
};

static vector<assertion> s_failed_primitive_asserts{};
static vector<assertion> s_passed_primitive_asserts{};
static vector<assertion> s_failed_container_asserts{};
static vector<assertion> s_passed_container_asserts{};
static string s_output_path = ".";
static size_t s_max_str_preview_len = 20;
static std::pair<char, char> constexpr s_special_chars[] {
  { '\a', 'a' },
  { '\b', 'b' },
  { '\f', 'f' },
  { '\n', 'n' },
  { '\r', 'r' },
  { '\t', 't' },
  { '\v', 'v' },
  { '\0', '0' },
};

void test::config::set_output_path(char const *const path)
{
  s_output_path = path;
}

void test::config::set_max_str_preview_len(size_t const len)
{
  s_max_str_preview_len = len;
}

size_t test::internal::max_str_preview_len()
{
  return s_max_str_preview_len;
}

static
void throw_if_file_not_open(FILE const *const file, char const *const pathname)
{
  if (file == nullptr)
  {
    stringstream err{};
    err << "failed to open file `" << pathname << "`";
    throw runtime_error(err.str());
  }
}

template <typename Ty>
requires test::primitive<Ty>
void assert_primitive(
  Ty const expected, Ty const actual,
  source_location const &loc)
{
  //              the bigger one               the smaller one
  Ty const diff = std::max(expected, actual) - std::min(expected, actual);
  // subraction order is important to avoid overflow!

  bool const passed = !static_cast<bool>(diff);

  stringstream serialized_vals{};
  serialized_vals
    << typeid(expected).name() << " | "
    << std::to_string(expected);

  if (passed)
    s_passed_primitive_asserts.emplace_back(serialized_vals.str(), loc);
  else
  {
    serialized_vals
      << " | " << std::to_string(actual)
      << " | " << std::to_string(diff);

    s_failed_primitive_asserts.emplace_back(serialized_vals.str(), loc);
  }
}

void test::assert_int8(
  int8_t const expected, int8_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_uint8(
  uint8_t const expected, uint8_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_int16(
  int16_t const expected, int16_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_uint16(
  uint16_t const expected, uint16_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_int32(
  int32_t const expected, int32_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_uint32(
  uint32_t const expected, uint32_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_int64(
  int64_t const expected, int64_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

void test::assert_uint64(
  uint64_t const expected, uint64_t const actual,
  source_location const loc)
{
  assert_primitive(expected, actual, loc);
}

static
void serialize_str_preview(
  char const *const str, size_t const len, stringstream &ss)
{
  ss << "len=" << len;

  if (len == 0)
    return;

  size_t const max_len = test::internal::max_str_preview_len();

  ss << " \"`";
  {
    std::string_view const content(str, std::min(len, max_len));

    for (size_t i = 0; i < content.size(); ++i)
    {
      char const ch = content[i];
      bool is_special = false;

      for (auto const [special, representation] : s_special_chars)
      {
        if (ch == special)
        {
          is_special = true;
          ss << '\\' << representation; // print escaped version
          break;
        }
      }

      if (!is_special)
        ss << ch; // print as is
    }
  }
  ss << '`';

  if (len <= max_len)
    ss << '"';
  else
  {
    size_t const num_hidden_chars = len - max_len;
    ss << "*... " << num_hidden_chars << " more*";
  }
}

void test::assert_cstr(
  char const *const expected, char const *const actual,
  test::str_opts const &options,
  source_location const loc)
{
  size_t const expected_len = strlen(expected);
  size_t const actual_len = strlen(actual);
  test::assert_cstr(expected, expected_len, actual, actual_len, options, loc);
}

void test::assert_cstr(
  char const *const expected, size_t const expected_len,
  char const *const actual, size_t const actual_len,
  test::str_opts const &options,
  source_location const loc)
{
  bool const passed = strcmp(expected, actual) == 0;

  stringstream serialized_values{};
  serialized_values << "char* | ";

  if (passed)
  {
    serialize_str_preview(expected, expected_len, serialized_values);
    s_passed_container_asserts.emplace_back(serialized_values.str(), loc);
  }
  else
  {
    auto const generate_file_pathname = [&loc](
      char const *const extension)
    {
      stringstream ss{};
      ss
        << fs::path(loc.file_name()).filename().string() << '@'
        << loc.function_name() << '(' << loc.line() << ',' << loc.column() << ')'
        << '.' << extension;
      return ss.str();
    };

    string const
      expected_pathname = generate_file_pathname("expected"),
      actual_pathname = generate_file_pathname("actual");

    auto const write_file = [&options](
      string const &pathname, char const *str, size_t const len)
    {
      FILE *const file = fopen(pathname.c_str(), "w");
      throw_if_file_not_open(file, pathname.c_str());

      if (!options.escape_special_chars)
      {
        fprintf(file, "%s", str);
        return;
      }

      for (size_t i = 0; i < len; ++i)
      {
        char const ch = str[i];
        bool is_special = false;

        for (auto const &pair : s_special_chars)
        {
          if (ch == pair.first)
          {
            is_special = true;
            fputc('\\', file);
            fputc(pair.second, file);
            break;
          }
        }

        if (!is_special)
          fputc(ch, file);
      }
    };

    write_file(expected_pathname, expected, expected_len);
    write_file(actual_pathname, actual, actual_len);

    serialized_values
      << '[' << expected_pathname << "](" << expected_pathname
      << ") | [" << actual_pathname << "](" << actual_pathname << ')';

    s_failed_container_asserts.emplace_back(serialized_values.str(), loc);
  }
}

void test::assert_stdstr(
  string const &expected, string const &actual,
  str_opts const &options, source_location loc)
{
  test::assert_cstr(expected.c_str(), expected.size(),
    actual.c_str(), actual.size(), options, loc);
}

void test::generate_report(char const *const name)
{
  FILE *const file = [name]()
  {
    string pathname = s_output_path;

    if (!pathname.ends_with("/") && !pathname.ends_with("\\"))
      pathname.push_back('/');

    pathname.append(name);
    pathname.append(".md");

    FILE *const f = fopen(pathname.c_str(), "w");
    throw_if_file_not_open(f, pathname.c_str());

    printf("generating report `%s`... ", pathname.c_str());

    return f;
  }();

  fprintf(file, "# %s\n\n", name);
  fprintf(file, "|   |   |\n");
  fprintf(file, "| - | - |\n");
  fprintf(file, "| failed | %zu |\n",
    s_failed_primitive_asserts.size() + s_failed_container_asserts.size());
  fprintf(file, "| passed | %zu |\n",
    s_passed_primitive_asserts.size() + s_passed_container_asserts.size());
  fprintf(file, "\n");

  if (s_failed_primitive_asserts.size() > 0)
  {
    fprintf(file, "## ❌ failed (primitive)\n\n");
    fprintf(file, "| type | expected | actual | diff | location (func:ln,col) | file |\n");
    fprintf(file, "| - | - | - | - | - | - |\n");

    for (auto const &[serialized_vals, loc] : s_failed_primitive_asserts)
    {
      fprintf(file, "| %s | %s:%zu,%zu | [%s](%s) |\n",
        serialized_vals.c_str(),
        loc.function_name(), loc.line(), loc.column(),
        loc.file_name(), loc.file_name());
    }

    fprintf(file, "\n");
  }

  if (s_failed_container_asserts.size() > 0)
  {
    fprintf(file, "## ❌ failed (container)\n\n");
    fprintf(file, "| type | expected | actual | location (func:ln,col) | file |\n");
    fprintf(file, "| - | - | - | - | - |\n");

    for (auto const &[serialized_vals, loc] : s_failed_container_asserts)
    {
      fprintf(file, "| %s | %s:%zu,%zu | [%s](%s) |\n",
        serialized_vals.c_str(),
        loc.function_name(), loc.line(), loc.column(),
        loc.file_name(), loc.file_name());
    }

    fprintf(file, "\n");
  }

  if (s_passed_primitive_asserts.size() > 0)
  {
    fprintf(file, "## ✅ passed (primitive)\n\n");
    fprintf(file, "| type | expected | location (func:ln,col) | file |\n");
    fprintf(file, "| - | - | - | - |\n");

    for (auto const &[serialized_vals, loc] : s_passed_primitive_asserts)
    {
      fprintf(file, "| %s | %s:%zu,%zu | [%s](%s) |\n",
        serialized_vals.c_str(),
        loc.function_name(), loc.line(), loc.column(),
        loc.file_name(), loc.file_name());
    }

    fprintf(file, "\n");
  }

  if (s_passed_container_asserts.size() > 0)
  {
    fprintf(file, "## ✅ passed (container)\n\n");
    fprintf(file, "| type | expected | location (func:ln,col) | file |\n");
    fprintf(file, "| - | - | - | - |\n");

    for (auto const &[serialized_vals, loc] : s_passed_container_asserts)
    {
      fprintf(file, "| %s | %s:%zu,%zu | [%s](%s) |\n",
        serialized_vals.c_str(),
        loc.function_name(), loc.line(), loc.column(),
        loc.file_name(), loc.file_name());
    }

    fprintf(file, "\n");
  }

  fclose(file);
  printf("done\n");

  // reset state to allow user to generate multiple independent reports
  s_failed_primitive_asserts.clear();
  s_passed_primitive_asserts.clear();
  s_failed_container_asserts.clear();
  s_passed_container_asserts.clear();
}
