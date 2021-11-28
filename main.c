#include <stdio.h>

// headers.h should only be included from implementation file
#include "headers.h"

// include headers that both include the same c.h header
#include A_H
#include B_H

int main(int argc, char** argv)
{
	printf("a() == %d\n", a());
	printf("b() == %d\n", b());
	return 0;
}
