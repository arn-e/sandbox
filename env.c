#include <stdio.h>
#include <stdlib.h>

struct jintArray
{
  int size;
  int *elements;
};

struct env_type 
{
  int *(*GetIntArrayElements)(struct jintArray);
  int *(*ReleaseIntArrayElements)(struct jintArray, int *native_array);  
};

int *GetIntArrayElementsFunc(struct jintArray array_object)
{

}

int *ReleaseIntArrayElementsFunc(struct jintArray array_object, int *native_array)
{

}

void create_jintArray(int size)
{
  struct jintArray jintArray_struct, *jintArray_ptr;
  jintArray_ptr = &jintArray_struct;

  jintArray_ptr->size = size;
  for (int i = 0; i < (jintArray_ptr->size); i ++){
    jintArray_ptr->elements[i] = i;
  }
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