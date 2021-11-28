// include null file next time
#undef A_H
#define A_H NULL_H

// include "c.h", or null if already included
#include C_H

static inline int a()
{
	return c() * 2;
}
