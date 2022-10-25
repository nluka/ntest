# example

|   |   |
| - | - |
| failed | 3 |
| passed | 3 |

## ❌ failed

| type | expected | actual | location (func:ln,col) | file |
| - | - | - | - | - |
| int | 0 | 1 | main:6,10 | [./main.cpp](./main.cpp) |
| char* | [main.cpp@main(9,10).expected](main.cpp@main(9,10).expected) | [main.cpp@main(9,10).actual](main.cpp@main(9,10).actual) | main:9,10 | [./main.cpp](./main.cpp) |
| std::vector\<int\> | [main.cpp@main(15,12).expected](main.cpp@main(15,12).expected) | [main.cpp@main(15,12).actual](main.cpp@main(15,12).actual) | main:15,12 | [./main.cpp](./main.cpp) |

## ✅ passed

| type | expected | location (func:ln,col) | file |
| - | - | - | - |
| int | 1 | main:5,10 | [./main.cpp](./main.cpp) |
| char* | len=12 "`Hello world!`" | main:8,10 | [./main.cpp](./main.cpp) |
| std::vector\<int\> | sz=4 __[__ `0`, `1`, `2`, `3`, __]__ | main:14,12 | [./main.cpp](./main.cpp) |

