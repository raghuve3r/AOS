#include<memtest.h>

shellcmd xsh_memtest(int nargs, char *args[])
{
      if(nargs > 2)
      {
	   kprintf("Enter Correct output\n");
	   return SYSERR;
      }
      else {
      if(nargs == 2 && strncmp(args[1], "--help", 7) == 0) 
	{
		printf("Use:\n");
		printf("\t%s [command]\n", args[0]);
		printf("Description:\n");
		printf("\tThis function will allocate the stack frame based on First Fit allocation\n");
		printf("\t--help\tdisplay this help and exit\n");
		return OK;
	}
	else {
	resume(create(sample, 1024, 20, "sample", 0));
	sleep(3);
	//int a = getmem6(sizeof(int));
	//int b = getmem6(sizeof(int));
	//int c = getmem6(sizeof(int));
}
}
return OK;
}
