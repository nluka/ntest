# short_example_report

Wed Mar 22 19:30:35 2023

3 failed

3 passed

| | Type | Expected | Actual | Location (fn:ln,col) | Source File |
| - | - | - | - | - | - |
| ❌ | int | 0 | 1 | int main():10,22 | short_example.cpp |
| ❌ | char* | [short_example.cpp@13,21.expected](short_example.cpp@13,21.expected) | [short_example.cpp@13,21.actual](short_example.cpp@13,21.actual) | int main():13,21 | short_example.cpp |
| ❌ | std::vector\<int\> | [short_example.cpp@18,25.expected](short_example.cpp@18,25.expected) | [short_example.cpp@18,25.actual](short_example.cpp@18,25.actual) | int main():18,25 | short_example.cpp |

| | Type | Expected | Location (fn:ln,col) | Source File |
| - | - | - | - | - |
| ✅ | int | 1 | int main():9,22 | short_example.cpp |
| ✅ | char* | len=12 <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;'>Hello world!</span> | int main():12,21 | short_example.cpp |
| ✅ | std::vector\<int\> | sz=4 __[__ <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 0'>0</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 1'>1</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 2'>2</span>, <span style='border: 1px solid darkgray;font-family: monospace;padding: 2px;white-space: pre-wrap;' title='index 3'>3</span>, __]__ | int main():19,25 | short_example.cpp |

