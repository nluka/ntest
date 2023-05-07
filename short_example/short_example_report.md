# short_example_report

Sun May  7 16:59:28 2023

3 failed

3 passed

| | Type | Expected | Actual | Location (fn:ln[,col]) | Source File |
| - | - | - | - | - | - |
| ❌ | int | 0 | 1 | int main():16 | short_example.cpp |
| ❌ | char* | [short_example.cpp_19.expected](short_example.cpp_19.expected) | [short_example.cpp_19.actual](short_example.cpp_19.actual) | int main():19 | short_example.cpp |
| ❌ | std::vector\<int\> | [short_example.cpp_24.expected](short_example.cpp_24.expected) | [short_example.cpp_24.actual](short_example.cpp_24.actual) | int main():24 | short_example.cpp |

| | Type | Expected | Location (fn:ln,col) | Source File |
| - | - | - | - | - |
| ✅ | int | 1 | int main():15 | short_example.cpp |
| ✅ | char* | len=12 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Hello world!</span> | int main():18 | short_example.cpp |
| ✅ | std::vector\<int\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 2'>2</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 3'>3</span>, __]__ | int main():25 | short_example.cpp |

