#include<future.h>


syscall future_set(future *f,int *value){
int mask;
mask=disable();
pid32 pid;

if(f->flag == 3)
{ 
if(f->state == 0||f->state == 1)
{
  f->value=*value;
  f->state = 2;
restore(mask);
  return OK;
}
restore(mask);
return SYSERR;
}


if(f->flag == 4)
{
 if(f->state == 0||f->state == 1)
{
if(f->get_queue.front==f->get_queue.rear)
{
if(f->set_queue.rear==1)
{
restore(mask);
return SYSERR;
}

f->set_queue.q[f->set_queue.rear]=getpid();
f->set_queue.rear=(f->set_queue.rear+1)%100;
restore(mask);
suspend(getpid());
}

  f->value = *value;
  f->state = 2;
  int i = 0;
  while(f->get_queue.front!=f->get_queue.rear)
{
  pid = f->get_queue.q[f->get_queue.front];
  f->get_queue.front = (f->get_queue.front+1) % 100;
  resume(pid);
  i++;
}
  restore(mask);
  return OK;
}
 restore(mask);
 return SYSERR;
}


if(f->flag==5)
{
if(f->state == 1)
{
 f->value = *value;
 f->state = 2;
 pid = f->get_queue.q[f->get_queue.front];
 f->get_queue.front = (f->get_queue.front+1)%100;
 resume(pid); 
}
if(f->get_queue.front == f->get_queue.rear)
{
 f->set_queue.q[f->set_queue.rear] = getpid();
 f->set_queue.rear = (f->set_queue.rear + 1)%100;
 suspend(getpid());
}
f->value = *value;
f->state = 2;
pid = f->get_queue.q[f->get_queue.front];
f->get_queue.front = (f->get_queue.front + 1) % 100;
resume(pid);
restore(mask);
return OK;
}}
