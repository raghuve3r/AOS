#include <future.h>

int n;                 //Definition for global variable 'n'
/*Now global variable n will be on Heap so it is accessible all the processes i.e. consume and produce*/
shellcmd xsh_prodcons(int nargs, char *args[])
{
future *f1, *f2,*f3;
f1=future_alloc(3);
f2=future_alloc(4);
f3 = future_alloc(5);

f2->get_queue.front = 0;
f2->get_queue.rear = 0;
f2->set_queue.rear=0;
f2->set_queue.front=0;
f3->get_queue.front = 0;
f3->get_queue.rear = 0;
f3->set_queue.front = 0;
f3->set_queue.rear = 0;
	if (nargs==2)
	  {	

		if(strncmp(args[1],"-f",2)==0)
		{
		  
		  resume(create(future_cons,1024,20,"fcons1",1,f1));
		  resume(create(future_prod,1024,20,"fprod1",1,f1));
		  
 		 		  
		  resume(create(future_cons,1024,20,"fcons2",1,f2));
		  resume(create(future_cons,1024,20,"fcons3",1,f2));
 		  resume(create(future_cons,1024,20,"fcons4",1,f2));
		  resume(create(future_cons,1024,20,"fcons5",1,f2));
		  resume(create(future_prod,1024,20,"fprod2",1,f2));
		  resume(create(future_cons,1024,20,"fcons6",1,f3));
		  resume(create(future_cons,1024,20,"fcons7",1,f3));
		  resume(create(future_cons,1024,20,"fcons8",1,f3));
		  resume(create(future_prod,1024,20,"fprod5",1,f3));
		  resume(create(future_prod,1024,20,"fprod3",1,f3));
		  resume(create(future_prod,1024,20,"fprod4",1,f3));
		sleep(1);
 future_free(f1);
 future_free(f2);
 future_free(f3);

		return OK;
		}
		
		if(strncmp(args[1],"--help",6)==0)
		{
 		printf("\n\nUse: %s -f \n\n", args[0]);
		printf("Description:\n");
		printf("\t Enter flag for use of futures\n");
		printf("\t--help\t display this help and exit\n");
		return OK;

		}
	}
		
			printf("Enter appropriate flag\n");
		return OK;
}
