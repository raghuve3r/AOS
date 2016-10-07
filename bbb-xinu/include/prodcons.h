#include<future.h>

#define SIZE 1024
char response[SIZE];
int n;

int produce(future *f,int slot, char *str);
int consume(future *f);
