#include <stdio.h>

int score(int collection[][*], int height, int width, int value, int level)
{
	printf("hello!");
	int lowest = 50000;
	int sum;

	for (int i = 0; i < width; i ++){
		sum = value + collection[level][i];
		if (sum < lowest) { lowest = sum; }
	}

	if (level < height){
		level ++;
		lowest = score(collection, height, width, lowest, level);
	}

	return lowest;
}

int path(int collection[][*], int height, int width)
{
	int lowest = 5000;

	for (int i = 0; i < width; i ++){
		int weight = score(collection, height, width, collection[0][i],1);
		if (weight < lowest){ lowest = weight; }
	}

	printf("lowest score : %i", lowest);
	return lowest;
}


int main(int argc, char const *argv[])
{
	int width = 3;
	int height = 3;
	int values[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
	int collection[width][height];
	int inc = 0;

	for (int i = 0; i < 3; i ++){
		for (int j = 0; j < 3; j ++){
			collection[i][j] = values[inc];
			inc ++;
		}
	}

	path(collection, height, width);

	return 0;
}

