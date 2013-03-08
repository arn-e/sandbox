#include <stdio.h>
#include <stdlib.h>

// struct with a common interface for varying data types
struct poly_struct
{
	void (*value)();
	void (*print)(struct poly_struct);
};

// returns the value of a char
char *char_value(char my_char)
{
	char *char_ptr = malloc(sizeof(char));
	char_ptr = my_char;
	return char_ptr;
}

// returns the value of an int
int *int_value(int my_int)
{
	int *int_ptr = malloc(sizeof(int));
	int_ptr = my_int;	
	return int_ptr;	
}

// print function for integers
void print_int( struct poly_struct a )
{
	int *my_int = a.value;
	printf("value is : %i\n", *my_int);	
}

// print function for chars
void print_char( struct poly_struct a )
{
	char *my_char = a.value;
	printf("value is : %c\n", *my_char);
}

// main, execution
int main()
{
	struct poly_struct int_struct;
	int_struct.print = &print_int;	
	int *my_int_value = int_value(25);	
	int_struct.value = &my_int_value;

	struct poly_struct char_struct;
	char_struct.print = &print_char;
	char *my_char_value = char_value('b'); 
	char_struct.value = &my_char_value;
	
	// both char and ints printed with the same function call
	char_struct.print(char_struct);
	int_struct.print(int_struct);
}



