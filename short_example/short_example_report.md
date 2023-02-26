# short_example_report

Sun Feb 26 15:36:01 2023

3 failed

3 passed

| | Type | Expected | Actual | Location (fn:ln,col) | Source File |
| - | - | - | - | - | - |
| ❌ | int | 0 | 1 | main:10,10 | C:\code\ntest\short_example\short_example.cpp |
| ❌ | char* | [short_example.cpp@main(13,10).expected](short_example.cpp@main(13,10).expected) | [short_example.cpp@main(13,10).actual](short_example.cpp@main(13,10).actual) | main:13,10 | C:\code\ntest\short_example\short_example.cpp |
| ❌ | std::vector\<int\> | [short_example.cpp@main(18,12).expected](short_example.cpp@main(18,12).expected) | [short_example.cpp@main(18,12).actual](short_example.cpp@main(18,12).actual) | main:18,12 | C:\code\ntest\short_example\short_example.cpp |

| | Type | Expected | Location (fn:ln,col) | Source File |
| - | - | - | - | - |
| ✅ | int | 1 | main:9,10 | C:\code\ntest\short_example\short_example.cpp |
| ✅ | char* | len=12 <span style='background-color: lightgray;border: 1px solid darkgray;border-radius: 5px;color: black;font-family: monospace;padding: 1px;white-space: pre-wrap;'>Hello world!</span>" | main:12,10 | C:\code\ntest\short_example\short_example.cpp |
| ✅ | std::vector\<int\> | sz=4 __[__ <span style='background-color: lightgray;border: 1px solid darkgray;border-radius: 5px;color: black;font-family: monospace;padding: 1px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='background-color: lightgray;border: 1px solid darkgray;border-radius: 5px;color: black;font-family: monospace;padding: 1px;white-space: pre-wrap;' title='index 1'>1</span>, <span style='background-color: lightgray;border: 1px solid darkgray;border-radius: 5px;color: black;font-family: monospace;padding: 1px;white-space: pre-wrap;' title='index 2'>2</span>, <span style='background-color: lightgray;border: 1px solid darkgray;border-radius: 5px;color: black;font-family: monospace;padding: 1px;white-space: pre-wrap;' title='index 3'>3</span>, __]__ | main:19,12 | C:\code\ntest\short_example\short_example.cpp |

