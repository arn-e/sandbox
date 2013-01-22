#include <stdio.h>
#include <stdlib.h>

int *addInt(int n, int m) {
  // int res[10];
  // res[0] = n;
  // res[1] = m;
  // int (*res_ptr)[10] = malloc(sizeof res);
  int *res_ptr = malloc(2 * sizeof(int));
  // res_ptr = &res;
  res_ptr[0] = n + m;
  res_ptr[1] = n * m;
  return res_ptr;
}

// int (*functionPtr)(int,int) = &addInt;

struct struct_type {
  char *name;
  int x;
  int *fake_array;
  int *(*functionPtr)(int,int);
};

// (*functionPtr) = &addInt;

int main(int argc, char const *argv[])
{
    int x = 6;
    int *x_ptr = &x;

    struct struct_type new_struct;
    struct struct_type *str_ptr;
    str_ptr = &new_struct;

    str_ptr->x = 5;
    str_ptr->name = "the dude";
    str_ptr->functionPtr = &addInt;
    str_ptr->fake_array = malloc(3 * sizeof(int));
    str_ptr->fake_array[0] = 1;
    str_ptr->fake_array[1] = 2;
    str_ptr->fake_array[2] = 3;
    str_ptr->fake_array[3] = 4;
    str_ptr->fake_array[3] = 5;
    str_ptr->fake_array[3] = 6;

    int *res = str_ptr->functionPtr(3,6);
    char *res_name = str_ptr->name;

    printf("%i\n", res[1]);
    printf("hi %s", res_name);

    return 0;

}
