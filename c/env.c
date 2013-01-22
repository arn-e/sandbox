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

int *GetIntArrayElementsFunc(struct jintArray jvm_array)
{
  int size = jvm_array.size;
  int *native_array = malloc(size * sizeof(int));

  for (int i = 0; i < size; i ++){
    native_array[i] = jvm_array.elements[i];
  }
  return native_array;
}

int *ReleaseIntArrayElementsFunc(struct jintArray jvm_array, int *native_array)
{
  free(native_array); 
  free(jvm_array.elements);
  return 0;
}

struct jintArray create_jintArray(int size)
{
  struct jintArray jvm_array;

  jvm_array.size = size;
  jvm_array.elements = malloc(size * sizeof(int));

  for (int i = 0; i < (jvm_array.size); i ++){
    jvm_array.elements[i] = i;
  }
  return jvm_array;
}

struct env_type create_env_structure() 
{
  struct env_type env_struct, *env_ptr;

  env_struct.GetIntArrayElements = &GetIntArrayElementsFunc;
  env_struct.ReleaseIntArrayElements = &ReleaseIntArrayElementsFunc;
  return env_struct;
}

int main(int argc, char const *argv[])
{
  struct jintArray jvm_array;
  jvm_array = create_jintArray(5);
  struct env_type env_struct = create_env_structure();
  struct env_type *env_ptr = &env_struct;
  struct env_type **env = &env_ptr;

  int *native_array;

  native_array = (*env)->GetIntArrayElements(jvm_array);  
  (*env)->ReleaseIntArrayElements(jvm_array, native_array);
  return 0;
}