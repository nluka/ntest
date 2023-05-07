#include <iostream>

#include "../ntest.hpp"

int main()
{
  {
    // do some initialization...
    auto const init_result = ntest::init();
    std::cout
      << init_result.num_files_removed << " residual files removed, "
      << init_result.num_files_failed_to_remove << " failed to be removed\n";
  }

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

  // runs for each assertion when the markdown report is being generated
  auto const assertion_callback = [](ntest::assertion const &a, bool passed) {
    if (!passed)
      std::cout << "failed: " << a.loc.file_name() << ':' << a.loc.line() << '\n';
  };

  {
    // generate a markdown report which details all assertions
    auto const gen_res = ntest::generate_report("short_example_report", assertion_callback);
    std::cout << gen_res.num_passes << " passed, " << gen_res.num_fails << " failed\n";
  }
}
