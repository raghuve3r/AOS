#include<future.h>

syscall future_free(future *f)
{
int mask=disable();
 if(f)
 {
   freemem(f,sizeof(future));
restore(mask);
   return OK;
 }
restore(mask);
 return SYSERR;
}
