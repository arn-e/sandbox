// ctest.c

#include <jni.h>
#include <stdio.h>


int basic_addition(int base)
{
  int sum;
  sum = (base + 1);
  return sum;
}

JNIEXPORT int JNICALL Java_HelloWorld_helloFromC
  (JNIEnv * env, jobject jobj, jintArray test_int, jint test_value)
{
    jint *carr;
    jint i, sum = 0;
    carr = (*env)->GetIntArrayElements(env, test_int,NULL);

    for (int i = 0; i < 3; i ++){
      printf("hello there %i", carr[i]);
    }
    (*env)->ReleaseIntArrayElements(env, test_int, carr, 0);
    // printf("hello my int %i\n", test_int);
    int new_number = basic_addition(test_value);
    printf("Hello from C!\n");
    printf("new number : %i", new_number);
    return 14;
}
