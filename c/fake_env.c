#include <stdio.h>
#include <stdlib.h>

int *GetIntArrayElementsFunc()
{

}

int *ReleaseIntArrayElementsFunc()
{

}

struct env_type 
{
  int *(*GetIntArrayElements)(int,int);
  int *(*ReleaseIntArrayElements)(int,int);  
};

struct jintArray
{
  int size;
  int *elements;
};

void create_jintArray(int *array_elements, int array_size)
{

}

void create_env_structure() 
{
  struct env_type env_struct, *env_ptr;
  env_ptr = &env_struct;

  env_ptr->GetIntArrayElements = &GetIntArrayElementsFunc;
  env_ptr->ReleaseIntArrayElements = &ReleaseIntArrayElementsFunc;
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}