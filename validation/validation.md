# validation

Sat Apr  1 19:37:30 2023

61 failed

43 passed

| | Type | Expected | Actual | Location (fn:ln,col) | Source File |
| - | - | - | - | - | - |
| ❌ | bool | true | false | main:58,12 | validation.cpp |
| ❌ | signed char | -128 | -28 | main:62,12 | validation.cpp |
| ❌ | signed char | 0 | 8 | main:64,12 | validation.cpp |
| ❌ | signed char | 127 | 105 | main:66,12 | validation.cpp |
| ❌ | unsigned char | 0 | 1 | main:70,12 | validation.cpp |
| ❌ | unsigned char | 255 | 224 | main:72,12 | validation.cpp |
| ❌ | short | -32768 | -32668 | main:76,12 | validation.cpp |
| ❌ | short | 0 | 42 | main:78,12 | validation.cpp |
| ❌ | short | 32767 | 32756 | main:80,12 | validation.cpp |
| ❌ | unsigned short | 0 | 1 | main:84,12 | validation.cpp |
| ❌ | unsigned short | 65535 | 65091 | main:86,12 | validation.cpp |
| ❌ | int | -2147483648 | -2147483548 | main:90,12 | validation.cpp |
| ❌ | int | 0 | 42 | main:92,12 | validation.cpp |
| ❌ | int | 2147483647 | 2147483646 | main:94,12 | validation.cpp |
| ❌ | unsigned int | 0 | 1 | main:98,12 | validation.cpp |
| ❌ | unsigned int | 4294967295 | 4294966851 | main:100,12 | validation.cpp |
| ❌ | __int64 | -9223372036854775808 | -9223372036854775708 | main:104,12 | validation.cpp |
| ❌ | __int64 | 0 | 42 | main:106,12 | validation.cpp |
| ❌ | __int64 | 9223372036854775807 | 9223372036854774806 | main:108,12 | validation.cpp |
| ❌ | unsigned __int64 | 0 | 1 | main:112,12 | validation.cpp |
| ❌ | unsigned __int64 | 18446744073709551615 | 18446744073709551573 | main:114,12 | validation.cpp |
| ❌ | char* | [validation.cpp@121,14.expected](validation.cpp@121,14.expected) | [validation.cpp@121,14.actual](validation.cpp@121,14.actual) | main:121,14 | validation.cpp |
| ❌ | char* | [validation.cpp@122,14.expected](validation.cpp@122,14.expected) | [validation.cpp@122,14.actual](validation.cpp@122,14.actual) | main:122,14 | validation.cpp |
| ❌ | char* | [validation.cpp@124,14.expected](validation.cpp@124,14.expected) | [validation.cpp@124,14.actual](validation.cpp@124,14.actual) | main:124,14 | validation.cpp |
| ❌ | char* | [validation.cpp@132,14.expected](validation.cpp@132,14.expected) | [validation.cpp@132,14.actual](validation.cpp@132,14.actual) | main:132,14 | validation.cpp |
| ❌ | char* | [validation.cpp@133,14.expected](validation.cpp@133,14.expected) | [validation.cpp@133,14.actual](validation.cpp@133,14.actual) | main:133,14 | validation.cpp |
| ❌ | char* | [validation.cpp@142,14.expected](validation.cpp@142,14.expected) | [validation.cpp@142,14.actual](validation.cpp@142,14.actual) | main:142,14 | validation.cpp |
| ❌ | char* | [validation.cpp@151,14.expected](validation.cpp@151,14.expected) | [validation.cpp@151,14.actual](validation.cpp@151,14.actual) | main:151,14 | validation.cpp |
| ❌ | char* | [validation.cpp@152,14.expected](validation.cpp@152,14.expected) | [validation.cpp@152,14.actual](validation.cpp@152,14.actual) | main:152,14 | validation.cpp |
| ❌ | std::vector\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>\> | [validation.cpp@157,14.expected](validation.cpp@157,14.expected) | [validation.cpp@157,14.actual](validation.cpp@157,14.actual) | main:157,14 | validation.cpp |
| ❌ | int [] | [validation.cpp@166,14.expected](validation.cpp@166,14.expected) | [validation.cpp@166,14.actual](validation.cpp@166,14.actual) | main:166,14 | validation.cpp |
| ❌ | int [] | [validation.cpp@167,14.expected](validation.cpp@167,14.expected) | [validation.cpp@167,14.actual](validation.cpp@167,14.actual) | main:167,14 | validation.cpp |
| ❌ | struct customer [] | [validation.cpp@194,14.expected](validation.cpp@194,14.expected) | [validation.cpp@194,14.actual](validation.cpp@194,14.actual) | main:194,14 | validation.cpp |
| ❌ | struct customer [] | [validation.cpp@195,14.expected](validation.cpp@195,14.expected) | [validation.cpp@195,14.actual](validation.cpp@195,14.actual) | main:195,14 | validation.cpp |
| ❌ | struct customer [] | [validation.cpp@196,14.expected](validation.cpp@196,14.expected) | [validation.cpp@196,14.actual](validation.cpp@196,14.actual) | main:196,14 | validation.cpp |
| ❌ | std::vector\<int\> | [validation.cpp@206,14.expected](validation.cpp@206,14.expected) | [validation.cpp@206,14.actual](validation.cpp@206,14.actual) | main:206,14 | validation.cpp |
| ❌ | std::vector\<int\> | [validation.cpp@207,14.expected](validation.cpp@207,14.expected) | [validation.cpp@207,14.actual](validation.cpp@207,14.actual) | main:207,14 | validation.cpp |
| ❌ | std::vector\<struct customer\> | [validation.cpp@234,14.expected](validation.cpp@234,14.expected) | [validation.cpp@234,14.actual](validation.cpp@234,14.actual) | main:234,14 | validation.cpp |
| ❌ | std::vector\<struct customer\> | [validation.cpp@235,14.expected](validation.cpp@235,14.expected) | [validation.cpp@235,14.actual](validation.cpp@235,14.actual) | main:235,14 | validation.cpp |
| ❌ | std::vector\<struct customer\> | [validation.cpp@236,14.expected](validation.cpp@236,14.expected) | [validation.cpp@236,14.actual](validation.cpp@236,14.actual) | main:236,14 | validation.cpp |
| ❌ | std::vector\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>\> | [validation.cpp@261,14.expected](validation.cpp@261,14.expected) | [validation.cpp@261,14.actual](validation.cpp@261,14.actual) | main:261,14 | validation.cpp |
| ❌ | std::vector\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>\> | [validation.cpp@262,14.expected](validation.cpp@262,14.expected) | [validation.cpp@262,14.actual](validation.cpp@262,14.actual) | main:262,14 | validation.cpp |
| ❌ | std::array\<int, 4\> | [validation.cpp@280,14.expected](validation.cpp@280,14.expected) | [validation.cpp@280,14.actual](validation.cpp@280,14.actual) | main:280,14 | validation.cpp |
| ❌ | std::array\<int, 4\> | [validation.cpp@281,14.expected](validation.cpp@281,14.expected) | [validation.cpp@281,14.actual](validation.cpp@281,14.actual) | main:281,14 | validation.cpp |
| ❌ | std::array\<struct customer, 3\> | [validation.cpp@303,14.expected](validation.cpp@303,14.expected) | [validation.cpp@303,14.actual](validation.cpp@303,14.actual) | main:303,14 | validation.cpp |
| ❌ | std::array\<struct customer, 3\> | [validation.cpp@304,14.expected](validation.cpp@304,14.expected) | [validation.cpp@304,14.actual](validation.cpp@304,14.actual) | main:304,14 | validation.cpp |
| ❌ | std::array\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, 4\> | [validation.cpp@328,14.expected](validation.cpp@328,14.expected) | [validation.cpp@328,14.actual](validation.cpp@328,14.actual) | main:328,14 | validation.cpp |
| ❌ | std::array\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, 4\> | [validation.cpp@329,14.expected](validation.cpp@329,14.expected) | [validation.cpp@329,14.actual](validation.cpp@329,14.actual) | main:329,14 | validation.cpp |
| ❌ | text file | [./files/expected.txt](./files/expected.txt) | [./files/a.txt](./files/a.txt) | main:334,12 | validation.cpp |
| ❌ | text file | [./files/expected.txt](./files/expected.txt) | [./files/b.txt](./files/b.txt) | main:335,12 | validation.cpp |
| ❌ | text file | file not found | [./files/a.txt](./files/a.txt) | main:337,12 | validation.cpp |
| ❌ | text file | [./files/expected.txt](./files/expected.txt) | file not found | main:338,12 | validation.cpp |
| ❌ | binary file | [./files/expected.bin](./files/expected.bin) | [./files/a.bin](./files/a.bin) | main:341,12 | validation.cpp |
| ❌ | binary file | [./files/expected.bin](./files/expected.bin) | [./files/b.bin](./files/b.bin) | main:342,12 | validation.cpp |
| ❌ | binary file | file not found | [./files/a.bin](./files/a.bin) | main:344,12 | validation.cpp |
| ❌ | binary file | [./files/expected.bin](./files/expected.bin) | file not found | main:345,12 | validation.cpp |
| ❌ | char* | [validation.cpp@357,14.expected](validation.cpp@357,14.expected) | [validation.cpp@357,14.actual](validation.cpp@357,14.actual) | main:357,14 | validation.cpp |
| ❌ | class std::runtime_error | to be thrown | different exception type was thrown | main:359,25 | validation.cpp |
| ❌ | class std::runtime_error | to be thrown | nothing was thrown | main:365,25 | validation.cpp |
| ❌ | struct custom_exception | to be thrown | nothing was thrown | main:378,25 | validation.cpp |
| ❌ | struct custom_exception | to be thrown | different exception type was thrown | main:385,25 | validation.cpp |

| | Type | Expected | Location (fn:ln,col) | Source File |
| - | - | - | - | - |
| ✅ | bool | true | main:57,12 | validation.cpp |
| ✅ | signed char | -128 | main:61,12 | validation.cpp |
| ✅ | signed char | 0 | main:63,12 | validation.cpp |
| ✅ | signed char | 127 | main:65,12 | validation.cpp |
| ✅ | unsigned char | 0 | main:69,12 | validation.cpp |
| ✅ | unsigned char | 255 | main:71,12 | validation.cpp |
| ✅ | short | -32768 | main:75,12 | validation.cpp |
| ✅ | short | 0 | main:77,12 | validation.cpp |
| ✅ | short | 32767 | main:79,12 | validation.cpp |
| ✅ | unsigned short | 0 | main:83,12 | validation.cpp |
| ✅ | unsigned short | 65535 | main:85,12 | validation.cpp |
| ✅ | int | -2147483648 | main:89,12 | validation.cpp |
| ✅ | int | 0 | main:91,12 | validation.cpp |
| ✅ | int | 2147483647 | main:93,12 | validation.cpp |
| ✅ | unsigned int | 0 | main:97,12 | validation.cpp |
| ✅ | unsigned int | 4294967295 | main:99,12 | validation.cpp |
| ✅ | __int64 | -9223372036854775808 | main:103,12 | validation.cpp |
| ✅ | __int64 | 0 | main:105,12 | validation.cpp |
| ✅ | __int64 | 9223372036854775807 | main:107,12 | validation.cpp |
| ✅ | unsigned __int64 | 0 | main:111,12 | validation.cpp |
| ✅ | unsigned __int64 | 18446744073709551615 | main:113,12 | validation.cpp |
| ✅ | char* | len=12 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Hello\nworld!</span> | main:123,14 | validation.cpp |
| ✅ | char* | len=26 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>abcdefghijklmno</span> *... 11 more* | main:125,14 | validation.cpp |
| ✅ | char* | len=26 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Testing code is</span> *... 11 more* | main:134,14 | validation.cpp |
| ✅ | char* | len=26 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Testing\0code\0is</span> *... 11 more* | main:143,14 | validation.cpp |
| ✅ | char* | len=10 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>\`Backtick\`</span> | main:149,14 | validation.cpp |
| ✅ | char* | len=10 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>\`Backtick\`</span> | main:150,14 | validation.cpp |
| ✅ | std::vector\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>\> | sz=1 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>\`Backtick\`</span>, __]__ | main:156,14 | validation.cpp |
| ✅ | int [] | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>,  *... 2 more* __]__ | main:168,14 | validation.cpp |
| ✅ | struct customer [] | sz=3 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>(Alice Smith, 22)</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>(Joe Schmoe, 100)</span>,  *... 1 more* __]__ | main:197,14 | validation.cpp |
| ✅ | std::vector\<int\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>,  *... 2 more* __]__ | main:208,14 | validation.cpp |
| ✅ | std::vector\<struct customer\> | sz=3 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>(Alice Smith, 22)</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>(Joe Schmoe, 100)</span>,  *... 1 more* __]__ | main:237,14 | validation.cpp |
| ✅ | std::vector\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>Testing</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>code</span>,  *... 2 more* __]__ | main:263,14 | validation.cpp |
| ✅ | std::vector\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>Testing\n</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>code\n</span>,  *... 2 more* __]__ | main:271,14 | validation.cpp |
| ✅ | std::array\<int, 4\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>,  *... 2 more* __]__ | main:282,14 | validation.cpp |
| ✅ | std::array\<struct customer, 3\> | sz=3 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>(Alice Smith, 22)</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>(Joe Schmoe, 100)</span>,  *... 1 more* __]__ | main:305,14 | validation.cpp |
| ✅ | std::array\<class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>>, 4\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>Testing</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>code</span>,  *... 2 more* __]__ | main:330,14 | validation.cpp |
| ✅ | text file | [./files/expected.txt](./files/expected.txt) | main:336,12 | validation.cpp |
| ✅ | binary file | [./files/expected.bin](./files/expected.bin) | main:343,12 | validation.cpp |
| ✅ | class std::runtime_error | to be thrown | main:351,25 | validation.cpp |
| ✅ | char* | len=23 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>some explanator</span> *... 8 more* | main:356,14 | validation.cpp |
| ✅ | struct custom_exception | to be thrown | main:372,25 | validation.cpp |
| ✅ | char* | len=22 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Something bad h</span> *... 7 more* | main:376,14 | validation.cpp |

