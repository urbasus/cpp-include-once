// include null file next time
#undef B_H
#define B_H NULL_H

// include "c.h", or null if already included
#include C_H

static inline int b()
{
	return c() + 3;
}
