#include <stdio.h>

int main(int argc, char const *argv[])
{
	char test_0[] = "hello0ooo0";
	printf("full string : %s\n",test_0);
	printf("what is 0   : %i\n",test_0[5]);
	test_0[3] = 0;
	printf("new string  : %s\n", test_0);
	return 0;
}

