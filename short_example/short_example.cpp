#include <iostream>

#include "../ntest.hpp"

int main()
{
  ntest::init();

  ntest::assert_int32(1, 1); // pass!
  ntest::assert_int32(0, 1); // fail!

  ntest::assert_cstr("Hello world!", "Hello world!"); // pass!
  ntest::assert_cstr("Hello world!", "Something else"); // fail!

  {
    std::vector<int> a { 0, 1, 2, 3 };
    std::vector<int> b { 0, 1, 9, 3 };
    ntest::assert_stdvec(a, b); // fail!
    ntest::assert_stdvec(a, a); // pass!
  }

  auto const res = ntest::generate_report("short_example_report");
  std::cout << res.num_passes << " passed, " << res.num_fails << " failed\n";
}
