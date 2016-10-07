#include <future.h>

future * future_alloc(int f_flag)
{
int mask;
mask=disable();
 future *f = (future *)getmem(sizeof(future));
 f->state = 0;
 f->flag = f_flag;
f->tid=-1;
 restore(mask);
 return f;
}
