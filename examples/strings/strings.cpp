#include <iostream>
#include <sstream>
#include <string>

#include "../../src/test.hpp"

int main()
{
  try
  {
    {
      char const *const hello_world = "Hello\nworld!";
      char const *const alphabet = "abcdefghijklmnopqrstuvwxyz";
      test::assert_cstr(hello_world, "hello world!");
      test::assert_cstr(hello_world, "Hello world");
      test::assert_cstr(hello_world, hello_world);
      test::assert_cstr(hello_world, alphabet);
      test::assert_cstr(alphabet, alphabet);
    }
    {
      std::string const expected = "Testing code is important.";
      test::assert_stdstr(expected, "Testing code is not important.");
      test::assert_stdstr(expected, "What is testing?");
      test::assert_stdstr(expected, expected);
    }
    {
      std::stringstream ss{};
      ss << "Testing" << '\0' << "code" << '\0' << "is" << '\0' << "important.";
      test::assert_stdstr("Testing code is important.", ss.str());
      test::assert_stdstr(ss.str(), ss.str());
    }

    test::generate_report("strings");
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
