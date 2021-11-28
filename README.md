# cpp-include-once

Concept for including headers only once.

*Note: This concept is a joke - prefer `#pragma once`.*

## How it works

Any implementation file starts by including a header file declaring:

- Macro for null path.
  - Linux: `#define NULL_H "/dev/null"`
  - Windows: `#define NULL_H "nul"`
    - ...OR, have an empty `null_file.h` in the project.
      - Null device presumably faster to open than empty file.
    - `nul` is a device on Windows, and some APIs demand file.
- Macros for header paths.
  - `#define C_H "c.h"`

Any file including a header does so using the header path macros:

```
// a.h
#include C_H
```

Header files implement the guard by redefining its header path macro to the null path:

```
// c.h
#undef C_H
#define C_H NULL_H
```

When a file tries to include a header that has already been included, the macro has been reset to include the null device, which is always empty.

## Pros

- Supported by all (?) C/C++ compilers and environments.
- Works the same across compilers.
  - `#pragma once` is implementation defined.
  - Recognized as a hard problem.
  - Issues not unheard of.
- Open and parse any header only once.
  - Include guards require opening headers multiple times AND parse its way all the way down to `#endif`.
- Simplified code formatting.
  - Formatting tools and standards may go for unconditional indentation for any conditionally compiled blocks of code - including code within an include guard!
    - Include guards often treated as an exception for such rules.

## Cons

- Tooling might not support it.
  - Null device timestamp doesn't make much sense.
  - Some Windows APIs may not accept device input.
- Poor acceptance among peers.
