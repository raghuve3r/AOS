#include<xinu.h>
#include<stdio.h>

shellcmd xsh_hello(int nargs, char *args[])
{
	if(nargs==2)
	{
		printf("Hello %s, Welcome to the world of Xinu!\n",args[1]);
	}
	else if(nargs<2)
	{
		printf("Please enter an argument\n");
	}
	else
	{
		printf("Too many arguments\n");
	}
}
