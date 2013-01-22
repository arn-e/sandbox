#include <stdio.h>

int score(int height, int width, int collection[width][height], int value, int level)
{
	int lowest;
	int sum;

	for (int i = 0; i < width; i ++){
		sum = (value + collection[level][i]);
		if (!lowest) { lowest = sum; }
		if (sum < lowest) { lowest = sum; }
	}

	if (level < height - 1){
		level ++;
		lowest = score(height, width, collection, lowest, level);
	}

	return lowest;
}

int path(int height, int width, int collection[width][height])
{
	int lowest;

	for (int i = 0; i < width; i ++){
		int weight = score(height, width, collection, collection[0][i],1);
		if (!lowest) { lowest = weight; }
		if (weight < lowest){ lowest = weight; }
	}
	
	return lowest;
}

void populate_array(int height, int width, int collection[width][height], int values[])
{
	int inc = 0;

	for (int i = 0; i < height; i ++){
		for (int j = 0; j < width; j ++){
			collection[i][j] = values[inc];
			inc ++;
		}
	}	
}

int main(int argc, char const *argv[])
{
	int width = 3; int height = 3;
	int values[] = {3, 1, 4, 1, 5, 9, 3, 6, 5};
	int collection[width][height];

	populate_array(height, width, collection, values);
	int result = path(height, width, collection);

	printf("lowest score : %i\n", result);
	return result;
}

