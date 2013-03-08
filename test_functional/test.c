
struct list {
  void *val;
  list *next;
};

//yeah, it's map; args is an extra pointer that is passed as the val to each 
//invocation of fn.
list *
map(list *l, void *(*fn)(void *, void *), void *args)

//yup, and filter too
list *
filter(list *l, bool (*fn)(void *, void *), void *args)

struct closure {
  void *(*fn)(list *);
  list *env;
};

struct envobj {
  void *val;
  ssize_t size;
};

//returns a lifted integer
envobj *
liftint(int a);

//this transforms a list into an environment
list * liftlist(list *l, ssize_t s)

closure *
bind(closure *c, void *(*fn)(list *), envobj *env);

void *
call(closure *c, envobj *env);

int
main(int argc, char **argv) {
  //LET THE MEMORY LEAKING BEGIN!!!
  //range returns a list of integers from start to finish
  iter(map(range(0, 10), dbl,NULL), printint, NULL);
  iter(filter(range(0, 10), odd, NULL), printint, NULL); 

  //Darker magic?  Not really...
  closure *addtwo = bind(NULL, add, liftint(2));
  closure *addten = bind(NULL, add, liftint(10));

  printf("%d\n", *(int *)call(addtwo, liftint(3)));
  printf("%d\n", *(int *)call(addten, liftint(3)));

  //all together now, with pseudo types everywhere woopie!!!
  list *vars = liftlist(range(0, 10), sizeof(int));
  list *res = lmap(vars, addtwo);
  iter(res, printint, NULL);

  exit(0);
}