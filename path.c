#include <stdio.h>


int weight(int matrix[][*], int size)
{
	for (int i = 0; int < size; int ++){
		int base[] = { 0, i } 
	}
	return 0;
}

int collect(int size, int *base, int level, int *next)
{
	for (int i = 1; i < size; i ++){
		int next[] = { i, level };	
		collect(size, *base, level +1)
	}
	// for (int i = level; i < size; i ++){
	// 	int next[] = { level, i };
	// 	collect(size, *base, level + 1, )
	// }

}

int main(int argc, char const *argv[])
{
	int width = 3;
	int height = 3;
	int values[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
	int matrix[width][height];
	int inc = 0;

	for (int i = 0; i < 3; i ++){
		for (int j = 0; j < 3; j ++){
			matrix[i][j] = values[inc];
			inc ++;
		}
	}

	// printing matrix

	// for (int i = 0; i < 3; i ++){
	// 	for (int j = 0; j < 3; j ++){
	// 		printf("\t %d",matrix[i][j]);
	// 		inc ++;
	// 	}
	// 	printf("\n");
	// }
	weight(matrix, 3);
	return 0;
}
