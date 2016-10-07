#include<future.h>

int future_cons(future *fut) {
  int status,x=0;
  status = future_get(fut, &x);
  if (status < 1) {
    printf("future_get failed\n");
    return -1;
  }
  printf("cons and state: %d %d\n", x,fut->flag);
 return OK;
}
