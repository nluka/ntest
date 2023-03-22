# validation

Wed Mar 22 19:31:00 2023

60 failed

41 passed

| | Type | Expected | Actual | Location (fn:ln,col) | Source File |
| - | - | - | - | - | - |
| ❌ | bool | true | false | int main():58,23 | validation.cpp |
| ❌ | signed char | -128 | -28 | int main():62,23 | validation.cpp |
| ❌ | signed char | 0 | 8 | int main():64,23 | validation.cpp |
| ❌ | signed char | 127 | 105 | int main():66,23 | validation.cpp |
| ❌ | unsigned char | 0 | 1 | int main():70,24 | validation.cpp |
| ❌ | unsigned char | 255 | 224 | int main():72,24 | validation.cpp |
| ❌ | short | -32768 | -32668 | int main():76,24 | validation.cpp |
| ❌ | short | 0 | 42 | int main():78,24 | validation.cpp |
| ❌ | short | 32767 | 32756 | int main():80,24 | validation.cpp |
| ❌ | unsigned short | 0 | 1 | int main():84,25 | validation.cpp |
| ❌ | unsigned short | 65535 | 65091 | int main():86,25 | validation.cpp |
| ❌ | int | -2147483648 | -2147483548 | int main():90,24 | validation.cpp |
| ❌ | int | 0 | 42 | int main():92,24 | validation.cpp |
| ❌ | int | 2147483647 | 2147483646 | int main():94,24 | validation.cpp |
| ❌ | unsigned int | 0 | 1 | int main():98,25 | validation.cpp |
| ❌ | unsigned int | 4294967295 | 4294966851 | int main():100,25 | validation.cpp |
| ❌ | long | -9223372036854775808 | -9223372036854775708 | int main():104,24 | validation.cpp |
| ❌ | long | 0 | 42 | int main():106,24 | validation.cpp |
| ❌ | long | 9223372036854775807 | 9223372036854774806 | int main():108,24 | validation.cpp |
| ❌ | unsigned long | 0 | 1 | int main():112,25 | validation.cpp |
| ❌ | unsigned long | 18446744073709551615 | 18446744073709551573 | int main():114,25 | validation.cpp |
| ❌ | char* | [validation.cpp@121,25.expected](validation.cpp@121,25.expected) | [validation.cpp@121,25.actual](validation.cpp@121,25.actual) | int main():121,25 | validation.cpp |
| ❌ | char* | [validation.cpp@122,25.expected](validation.cpp@122,25.expected) | [validation.cpp@122,25.actual](validation.cpp@122,25.actual) | int main():122,25 | validation.cpp |
| ❌ | char* | [validation.cpp@124,25.expected](validation.cpp@124,25.expected) | [validation.cpp@124,25.actual](validation.cpp@124,25.actual) | int main():124,25 | validation.cpp |
| ❌ | char* | [validation.cpp@132,27.expected](validation.cpp@132,27.expected) | [validation.cpp@132,27.actual](validation.cpp@132,27.actual) | int main():132,27 | validation.cpp |
| ❌ | char* | [validation.cpp@133,27.expected](validation.cpp@133,27.expected) | [validation.cpp@133,27.actual](validation.cpp@133,27.actual) | int main():133,27 | validation.cpp |
| ❌ | char* | [validation.cpp@142,27.expected](validation.cpp@142,27.expected) | [validation.cpp@142,27.actual](validation.cpp@142,27.actual) | int main():142,27 | validation.cpp |
| ❌ | char* | [validation.cpp@151,25.expected](validation.cpp@151,25.expected) | [validation.cpp@151,25.actual](validation.cpp@151,25.actual) | int main():151,25 | validation.cpp |
| ❌ | char* | [validation.cpp@152,27.expected](validation.cpp@152,27.expected) | [validation.cpp@152,27.actual](validation.cpp@152,27.actual) | int main():152,27 | validation.cpp |
| ❌ | int [] | [validation.cpp@161,24.expected](validation.cpp@161,24.expected) | [validation.cpp@161,24.actual](validation.cpp@161,24.actual) | int main():161,24 | validation.cpp |
| ❌ | int [] | [validation.cpp@162,24.expected](validation.cpp@162,24.expected) | [validation.cpp@162,24.actual](validation.cpp@162,24.actual) | int main():162,24 | validation.cpp |
| ❌ | customer [] | [validation.cpp@189,24.expected](validation.cpp@189,24.expected) | [validation.cpp@189,24.actual](validation.cpp@189,24.actual) | int main():189,24 | validation.cpp |
| ❌ | customer [] | [validation.cpp@190,24.expected](validation.cpp@190,24.expected) | [validation.cpp@190,24.actual](validation.cpp@190,24.actual) | int main():190,24 | validation.cpp |
| ❌ | customer [] | [validation.cpp@191,24.expected](validation.cpp@191,24.expected) | [validation.cpp@191,24.actual](validation.cpp@191,24.actual) | int main():191,24 | validation.cpp |
| ❌ | std::vector\<int\> | [validation.cpp@201,27.expected](validation.cpp@201,27.expected) | [validation.cpp@201,27.actual](validation.cpp@201,27.actual) | int main():201,27 | validation.cpp |
| ❌ | std::vector\<int\> | [validation.cpp@202,27.expected](validation.cpp@202,27.expected) | [validation.cpp@202,27.actual](validation.cpp@202,27.actual) | int main():202,27 | validation.cpp |
| ❌ | std::vector\<customer\> | [validation.cpp@229,27.expected](validation.cpp@229,27.expected) | [validation.cpp@229,27.actual](validation.cpp@229,27.actual) | int main():229,27 | validation.cpp |
| ❌ | std::vector\<customer\> | [validation.cpp@230,27.expected](validation.cpp@230,27.expected) | [validation.cpp@230,27.actual](validation.cpp@230,27.actual) | int main():230,27 | validation.cpp |
| ❌ | std::vector\<customer\> | [validation.cpp@231,27.expected](validation.cpp@231,27.expected) | [validation.cpp@231,27.actual](validation.cpp@231,27.actual) | int main():231,27 | validation.cpp |
| ❌ | std::vector\<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>\> | [validation.cpp@256,27.expected](validation.cpp@256,27.expected) | [validation.cpp@256,27.actual](validation.cpp@256,27.actual) | int main():256,27 | validation.cpp |
| ❌ | std::vector\<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>\> | [validation.cpp@257,27.expected](validation.cpp@257,27.expected) | [validation.cpp@257,27.actual](validation.cpp@257,27.actual) | int main():257,27 | validation.cpp |
| ❌ | std::array\<int, 4\> | [validation.cpp@267,27.expected](validation.cpp@267,27.expected) | [validation.cpp@267,27.actual](validation.cpp@267,27.actual) | int main():267,27 | validation.cpp |
| ❌ | std::array\<int, 4\> | [validation.cpp@268,27.expected](validation.cpp@268,27.expected) | [validation.cpp@268,27.actual](validation.cpp@268,27.actual) | int main():268,27 | validation.cpp |
| ❌ | std::array\<customer, 3\> | [validation.cpp@290,27.expected](validation.cpp@290,27.expected) | [validation.cpp@290,27.actual](validation.cpp@290,27.actual) | int main():290,27 | validation.cpp |
| ❌ | std::array\<customer, 3\> | [validation.cpp@291,27.expected](validation.cpp@291,27.expected) | [validation.cpp@291,27.actual](validation.cpp@291,27.actual) | int main():291,27 | validation.cpp |
| ❌ | std::array\<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, 4\> | [validation.cpp@315,27.expected](validation.cpp@315,27.expected) | [validation.cpp@315,27.actual](validation.cpp@315,27.actual) | int main():315,27 | validation.cpp |
| ❌ | std::array\<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, 4\> | [validation.cpp@316,27.expected](validation.cpp@316,27.expected) | [validation.cpp@316,27.actual](validation.cpp@316,27.actual) | int main():316,27 | validation.cpp |
| ❌ | text file | [./files/expected.txt](./files/expected.txt) | [./files/a.txt](./files/a.txt) | int main():321,28 | validation.cpp |
| ❌ | text file | [./files/expected.txt](./files/expected.txt) | [./files/b.txt](./files/b.txt) | int main():322,28 | validation.cpp |
| ❌ | text file | file not found | [./files/a.txt](./files/a.txt) | int main():324,28 | validation.cpp |
| ❌ | text file | [./files/expected.txt](./files/expected.txt) | file not found | int main():325,28 | validation.cpp |
| ❌ | binary file | [./files/expected.bin](./files/expected.bin) | [./files/a.bin](./files/a.bin) | int main():328,30 | validation.cpp |
| ❌ | binary file | [./files/expected.bin](./files/expected.bin) | [./files/b.bin](./files/b.bin) | int main():329,30 | validation.cpp |
| ❌ | binary file | file not found | [./files/a.bin](./files/a.bin) | int main():331,30 | validation.cpp |
| ❌ | binary file | [./files/expected.bin](./files/expected.bin) | file not found | int main():332,30 | validation.cpp |
| ❌ | char* | [validation.cpp@344,25.expected](validation.cpp@344,25.expected) | [validation.cpp@344,25.actual](validation.cpp@344,25.actual) | int main():344,25 | validation.cpp |
| ❌ | std::runtime_error | to be thrown | different exception type was thrown | int main():346,58 | validation.cpp |
| ❌ | std::runtime_error | to be thrown | nothing was thrown | int main():352,58 | validation.cpp |
| ❌ | custom_exception | to be thrown | nothing was thrown | int main():365,56 | validation.cpp |
| ❌ | custom_exception | to be thrown | different exception type was thrown | int main():372,56 | validation.cpp |

| | Type | Expected | Location (fn:ln,col) | Source File |
| - | - | - | - | - |
| ✅ | bool | true | int main():57,23 | validation.cpp |
| ✅ | signed char | -128 | int main():61,23 | validation.cpp |
| ✅ | signed char | 0 | int main():63,23 | validation.cpp |
| ✅ | signed char | 127 | int main():65,23 | validation.cpp |
| ✅ | unsigned char | 0 | int main():69,24 | validation.cpp |
| ✅ | unsigned char | 255 | int main():71,24 | validation.cpp |
| ✅ | short | -32768 | int main():75,24 | validation.cpp |
| ✅ | short | 0 | int main():77,24 | validation.cpp |
| ✅ | short | 32767 | int main():79,24 | validation.cpp |
| ✅ | unsigned short | 0 | int main():83,25 | validation.cpp |
| ✅ | unsigned short | 65535 | int main():85,25 | validation.cpp |
| ✅ | int | -2147483648 | int main():89,24 | validation.cpp |
| ✅ | int | 0 | int main():91,24 | validation.cpp |
| ✅ | int | 2147483647 | int main():93,24 | validation.cpp |
| ✅ | unsigned int | 0 | int main():97,25 | validation.cpp |
| ✅ | unsigned int | 4294967295 | int main():99,25 | validation.cpp |
| ✅ | long | -9223372036854775808 | int main():103,24 | validation.cpp |
| ✅ | long | 0 | int main():105,24 | validation.cpp |
| ✅ | long | 9223372036854775807 | int main():107,24 | validation.cpp |
| ✅ | unsigned long | 0 | int main():111,25 | validation.cpp |
| ✅ | unsigned long | 18446744073709551615 | int main():113,25 | validation.cpp |
| ✅ | char* | len=12 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Hello\nworl</span> *... 2 more* | int main():123,25 | validation.cpp |
| ✅ | char* | len=26 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>abcdefghij</span> *... 16 more* | int main():125,25 | validation.cpp |
| ✅ | char* | len=26 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Testing co</span> *... 16 more* | int main():134,27 | validation.cpp |
| ✅ | char* | len=26 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Testing\0co</span> *... 16 more* | int main():143,27 | validation.cpp |
| ✅ | char* | len=10 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>\`Backtick\`</span> | int main():149,25 | validation.cpp |
| ✅ | char* | len=10 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>\`Backtick\`</span> | int main():150,27 | validation.cpp |
| ✅ | int [] | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>,  *... 2 more* __]__ | int main():163,24 | validation.cpp |
| ✅ | customer [] | sz=3 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>(Alice Smith, 22)</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>(Joe Schmoe, 100)</span>,  *... 1 more* __]__ | int main():192,24 | validation.cpp |
| ✅ | std::vector\<int\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>,  *... 2 more* __]__ | int main():203,27 | validation.cpp |
| ✅ | std::vector\<customer\> | sz=3 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>(Alice Smith, 22)</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>(Joe Schmoe, 100)</span>,  *... 1 more* __]__ | int main():232,27 | validation.cpp |
| ✅ | std::vector\<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>Testing</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>code</span>,  *... 2 more* __]__ | int main():258,27 | validation.cpp |
| ✅ | std::array\<int, 4\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>,  *... 2 more* __]__ | int main():269,27 | validation.cpp |
| ✅ | std::array\<customer, 3\> | sz=3 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>(Alice Smith, 22)</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>(Joe Schmoe, 100)</span>,  *... 1 more* __]__ | int main():292,27 | validation.cpp |
| ✅ | std::array\<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, 4\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>Testing</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>code</span>,  *... 2 more* __]__ | int main():317,27 | validation.cpp |
| ✅ | text file | [./files/expected.txt](./files/expected.txt) | int main():323,28 | validation.cpp |
| ✅ | binary file | [./files/expected.bin](./files/expected.bin) | int main():330,30 | validation.cpp |
| ✅ | std::runtime_error | to be thrown | int main():338,58 | validation.cpp |
| ✅ | char* | len=23 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>some expla</span> *... 13 more* | int main():343,25 | validation.cpp |
| ✅ | custom_exception | to be thrown | int main():359,56 | validation.cpp |
| ✅ | char* | len=22 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Something </span> *... 12 more* | int main():363,25 | validation.cpp |

