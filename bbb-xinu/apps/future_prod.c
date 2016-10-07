#include <future.h>

int future_prod(future *fut) {
  int i = 1;
  int status = future_set(fut, &i);
  if(status<1) printf("\nfuture set failed");
  else
  return OK;
}
