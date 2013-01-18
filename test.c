#include <stdio.h>

struct element {
   	int x;
   	int y;
   	struct element *next;
};

int * collect(int size, int base[], int level)
{
	if (level == size) { return base; }

	for (int i = 1; i < size; i ++){
		int next[] = { i, level };
		// int first_elem = base[0];
		int *new_base[] = { base , next };

		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 2; j ++){
				printf("%d", new_base[i][j]);
						
			}

			
		}
		printf("\n");		

		int next_level = level + 1;
		collect(size, base, next_level);
	}
	// printf("%ld",sizeof(*base));
	// printf("\n");
	
	return base;
}

int main(int argc, char const *argv[])
{
	struct element e;
	e.x = 0;
	e.y = 0;

	int base[] = { 0, 0 };
	collect(4, base, 1);
	return 0;
}

// int main(int argc, char const *argv[])
// {
	
// 	struct account {
// 	   	int account_number;
// 	   	char *first_name;
// 	   	char *last_name;
// 	   	float balance;
// 	};

// 	struct account s;
	
// 	s.first_name = "hi";

// 	printf("%s",s.first_name);
// 	return 0;
// }
