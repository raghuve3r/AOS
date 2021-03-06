    #include <xinu.h>

    #include <stdio.h>

    #include <string.h>

    #define BUFFSIZE 1024

    shellcmd xsh_sendmsg(int nargs, char *args[]) {
     

    /* Output info for '--help' argument */

    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) 

    {

    printf("Usage: %s\n\n", args[0]);

    printf("Description:\n");

    printf("\tDisplays a welcome message for the given user name.\n");

    printf("Options (one per invocation):\n");

    printf("\t--help\tdisplay this help and exit\n");

    return 0;

    }

     

    /* Check argument count */

    /* If argument count is greater than 2, then there are too many arguments*/

    if (nargs > 2) 

    {

    fprintf(stderr, "%s: too many arguments\n", args[0]);

    return 1;

    }

     

    /* If argument count is less than 2, then there are too few arguments*/

    if (nargs < 2) 

    {

    fprintf(stderr, "%s: too few arguments\n", args[0]);

    return 1;

    }

     

    /* Check for invalid characters in the string. Display error message in the command. */

    //int i = 0;

    /*for(i = 0; args[1][i] != '\0'; i++ )

    {

    }*/


    udp_init();

    kprintf("\nUDP table initialized !!");

    int32 slot =0;

    uint32 target_ip;

    char tempbuff[BUFFSIZE];

    //bzero(tempbuff, BUFFSIZE);

    dot2ip("192.168.1.100",&target_ip);

    slot=udp_register(target_ip,8000,8000);

    kprintf("\nSlot obtained : %d",slot);

    udp_send(slot,args[1],strlen(args[1]));

    kprintf("\nMessage sent \n");

    udp_recv(slot,tempbuff,BUFFSIZE,15000);

    printf("Message Received :%s\n",tempbuff);

    return 0;

    }
