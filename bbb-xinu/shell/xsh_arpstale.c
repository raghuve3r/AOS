#include<xinu.h>

shellcmd xsh_arpstale(int argc, char *argv[])
{
int i,j1,j2,count=0;
uint32 k1,k2;
pid32 newpid1,newpid2;
byte buffer1[ETH_ADDR_LEN],buffer2[ETH_ADDR_LEN];
struct arpentry *arptr;
arp_resolve(3232235876,buffer1);
arptr=&arpcache[0];
newpid1=arptr->arpid;
j1=arptr->arstate;
k1=arptr->arpaddr;
for(i=0;i<ARP_HALEN;i++)
{
buffer1[i]=arptr->arhaddr[i];
}

printf("ARP State:%d\n",arptr->arstate);
printf("IP Address: ");
printf("%u\n",arptr->arpaddr);

printf("MAC Address: ");
for(i=0;i<ARP_HALEN;i++)
{
printf(":%02X",arptr->arhaddr[i]);
}
printf("\n");
 
sleep(300);

printf("ARP State:%d\n",arptr->arstate);
printf("IP Address: ");
printf("%u\n",arptr->arpaddr);

printf("MAC Address: ");
for(i=0;i<ARP_HALEN;i++)
{
printf("%h",arptr->arhaddr[i]);
}
printf("\n");

newpid2=arptr->arpid;
j2=arptr->arstate;
k2=arptr->arpaddr;
for(i=0;i<ARP_HALEN;i++)
{
buffer2[i]=arptr->arhaddr[i];
}

if(newpid1==newpid2 && j1==j2 && k1==k2)
{
for(i=0;i<ARP_HALEN;i++)
{
if(buffer1[i]!=buffer2[i])
count++;
}
if(count==0)
{
printf("Stale Information\n");
arpcache[0].arstate=0;
memset((char *)&arpcache[0],NULLCH,sizeof(struct arpentry));
}
}

printf("ARP State:%d\n",arptr->arstate);
printf("IP Address: ");
printf("%u\n",arptr->arpaddr);

printf("MAC Address: ");
for(i=0;i<ARP_HALEN;i++)
{
printf("%h",arptr->arhaddr[i]);
}
printf("\n");
}

