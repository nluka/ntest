#include <iostream>

#include "../../src/test.hpp"

int main()
{
  try
  {
    // int8
    test::assert_int8(INT8_MIN, INT8_MIN);       // pass
    test::assert_int8(INT8_MIN, INT8_MIN + 100); // fail
    test::assert_int8(0, 8);                     // pass
    test::assert_int8(0, 8);                     // fail
    test::assert_int8(INT8_MAX, INT8_MAX);       // pass
    test::assert_int8(INT8_MAX, INT8_MAX - 22);  // fail

    // uint8
    test::assert_uint8(0, 0);                        // pass
    test::assert_uint8(0, 1);                        // fail
    test::assert_uint8(UINT8_MAX, UINT8_MAX);        // pass
    test::assert_uint8(UINT8_MAX, UINT8_MAX - 444);  // fail

    // in16
    test::assert_int16(INT16_MIN, INT16_MIN);       // pass
    test::assert_int16(INT16_MIN, INT16_MIN + 100); // fail
    test::assert_int16(0, 0);                       // pass
    test::assert_int16(0, 42);                      // fail
    test::assert_int16(INT16_MAX, INT16_MAX);       // pass
    test::assert_int16(INT16_MAX, INT16_MAX - 22);  // fail

    // uint16
    test::assert_uint16(0, 0);                          // pass
    test::assert_uint16(0, 1);                          // fail
    test::assert_uint16(UINT16_MAX, UINT16_MAX);        // pass
    test::assert_uint16(UINT16_MAX, UINT16_MAX - 444);  // fail

    // int32
    test::assert_int32(INT32_MIN, INT32_MIN);       // pass
    test::assert_int32(INT32_MIN, INT32_MIN + 100); // fail
    test::assert_int32(0, 0);                       // pass
    test::assert_int32(0, 42);                      // fail
    test::assert_int32(INT32_MAX, INT32_MAX);       // pass
    test::assert_int32(INT32_MAX, INT32_MAX - 22);  // fail

    // uint32
    test::assert_uint32(0, 0);                          // pass
    test::assert_uint32(0, 1);                          // fail
    test::assert_uint32(UINT32_MAX, UINT32_MAX);        // pass
    test::assert_uint32(UINT32_MAX, UINT32_MAX - 444);  // fail

    // int64
    test::assert_int64(INT64_MIN, INT64_MIN);       // pass
    test::assert_int64(INT64_MIN, INT64_MIN + 100); // fail
    test::assert_int64(0, 0);                       // pass
    test::assert_int64(0, 42);                      // fail
    test::assert_int64(INT64_MAX, INT64_MAX);       // pass
    test::assert_int64(INT64_MAX, INT64_MAX - 22);  // fail

    // uint64_t
    test::assert_uint64(0, 0);                          // pass
    test::assert_uint64(0, 1);                          // fail
    test::assert_uint64(UINT64_MAX, UINT64_MAX);        // pass
    test::assert_uint64(UINT64_MAX, UINT64_MAX - 444);  // fail

    test::generate_report("primitives");
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
