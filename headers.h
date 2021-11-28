// this header should only be included in implementation files

// declare macro for the null header
#if defined(_WIN32) || defined(_WIN64)
#define NULL_H "nul"
#else
#define NULL_H "/dev/null"
#endif

// declare header path macros
#define A_H "a.h"
#define B_H "b.h"
#define C_H "c.h"
