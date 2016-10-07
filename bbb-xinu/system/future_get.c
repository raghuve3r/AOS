#include<future.h>


syscall future_get(future *f, int *value){

int mask;
pid32 pid;
mask=disable();
if(f->flag == 3)
{
 if(f->state == 0)
 {
  pid = getpid();
  if(pid<0)
   { 
	restore(mask);
	return SYSERR;
   }
if(f->tid!=-1)
{
restore(mask);
return SYSERR;
}
  f->tid = pid;

  f->state = 1;
 }
 while(f->state == 1)
 {
  sleep(0.1);
 }
   *value = f->value;
   restore(mask);
   return OK;
}


if(f->flag == 4)
{
if(f->set_queue.front!=f->set_queue.rear)
{
pid=f->set_queue.q[f->set_queue.front];
f->set_queue.front=(f->set_queue.front+1)%100;
resume(pid);
sleep(0.1);
}

 if(f->state == 0)
 {
  pid = getpid();
  if((f->get_queue.rear+1)%100==f->get_queue.front)
{
restore(mask);
return SYSERR;
}
  f->get_queue.q[f->get_queue.rear] = pid;
  f->get_queue.rear = (f->get_queue.rear+1) % 100;
  f->state = 1;
  suspend(pid);
 }
 while(f->state == 1)
 {
  pid = getpid();
 if((f->get_queue.rear+1)%100==f->get_queue.front)
{
restore(mask);
return SYSERR;
}

  f->get_queue.q[f->get_queue.rear] = pid;
  f->get_queue.rear = (f->get_queue.rear+1) % 100;
  suspend(pid);
 }
*value = f->value;
restore(mask);
return OK;
}

if(f->flag==5)
{
if(f->set_queue.rear!=f->set_queue.front)
{
 pid = f->set_queue.q[f->set_queue.front];
 f->set_queue.front = (f->set_queue.front + 1) % 100;
 resume(pid);
 sleep(0.1);
}
else if(f->set_queue.rear == f->set_queue.front)
{
 f->get_queue.q[f->get_queue.rear] = getpid();
 f->get_queue.rear = (f->get_queue.rear + 1) % 100;
 f->state = 1;
 suspend(getpid());
}
if(f->state == 2)
{
 *value = f->value;
 restore(mask);
 return OK;
}
}

}
/*
if(f->state==FUTURE_EMPTY || f->state==FUTURE_WAITING)
{
f->pid = getpid();
f->state=1;
//wait till the state becomes 2
}
else{
*value=f->value;
f->state=FUTURE_VALID;
//future_free(f);
return OK;
} */
