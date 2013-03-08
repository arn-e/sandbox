#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;

	// also comment
	printf("You are %d miles away.\n", distance);

	return 0;
}

// why does the compiler not throw an error, since the main function
// is being called without parameters (presumably?)