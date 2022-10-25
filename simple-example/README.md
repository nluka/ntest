
This example walks through the basics of ntest.

To use ntest, copy [ntest.cpp](/ntest.cpp) and [ntest.hpp](/ntest.hpp) somewhere into your project, and create a translation unit for your tester program. In this example, our filesystem looks like:

```
ntest
│  ntest.cpp
|  ntest.hpp
|  ...
|
└───simple-example/
    │  main.cpp
```

`ntest/simple-example/main.cpp` is our tester program:

```cpp
#include "../ntest.hpp"

int main()
{
  ntest::assert_int32(1, 1); // pass!
  ntest::assert_int32(0, 1); // fail!

  ntest::assert_cstr("Hello world!", "Hello world!"); // pass!
  ntest::assert_cstr("Hello world!", "Something else"); // fail!

  {
    std::vector<int> a { 0, 1, 2, 3 };
    std::vector<int> b { 0, 1, 9, 3 };
    ntest::assert_stdvec(a, a); // pass!
    ntest::assert_stdvec(a, b); // fail!
  }

  ntest::generate_report("example");
}

```

After compiling and running the tester program, several files are generated:

```
ntest
│  ntest.cpp
|  ntest.hpp
|  ...
|
└───simple-example/
    │  main.cpp
    |  simple.md !
    |  main.cpp@main(9,10).expected !
    |  main.cpp@main(9,10).actual !
    |  main.cpp@main(15,12).expected !
    |  main.cpp@main(15,12).actual !

! = generated
```

- `simple.md` is a markdown report of our assertions
- `*.{expected,actual}` are text files containing the serialized expected and actual value of a failed assertion - diff these to see how the values differ

In this example, the assertion:

```cpp
std::vector<int> a { 0, 1, 2, 3 };    /* line 30 */
std::vector<int> b { 0, 1, 9, 3 };    /* line 31 */
ntest::assert_stdvec(a, b); // fail!  /* line 33 */
```

generates the files:
- `main.cpp@main(15,12).expected`
- `main.cpp@main(15,12).actual`

whose diff is:

```diff
0
1
-2
+9
3
```

and the generated markdown report informs us of this failing assertion, as well as all the other assertions we made:

--- START OF GENERATED MARKDOWN REPORT ---

## simple

|   |   |
| - | - |
| failed | 3 |
| passed | 3 |

### ❌ failed

| type | expected | actual | location (func:ln,col) | file |
| - | - | - | - | - |
| int | 0 | 1 | main:6,10 | [./main.cpp](./main.cpp) |
| char* | [main.cpp@main(9,10).expected](main.cpp@main(9,10).expected) | [main.cpp@main(9,10).actual](main.cpp@main(9,10).actual) | main:9,10 | [./main.cpp](./main.cpp) |
| std::vector\<int\> | [main.cpp@main(15,12).expected](main.cpp@main(15,12).expected) | [main.cpp@main(15,12).actual](main.cpp@main(15,12).actual) | main:15,12 | [./main.cpp](./main.cpp) |

### ✅ passed

| type | expected | location (func:ln,col) | file |
| - | - | - | - |
| int | 1 | main:5,10 | [./main.cpp](./main.cpp) |
| char* | len=12 "`Hello world!`" | main:8,10 | [./main.cpp](./main.cpp) |
| std::vector\<int\> | sz=4 __[__ `0`, `1`, `2`, `3`, __]__ | main:14,12 | [./main.cpp](./main.cpp) |

--- END OF GENERATED MARKDOWN REPORT ---
