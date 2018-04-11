//server
#include<string.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<net/if_arp.h>
int main()
{
int sd,b,cd;
struct fname[50],op[1000];
struct sockaddr_in caddr,saddr;
FILE *fp;
socklen_t clen=sizeof(caddr);
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd!=-1)
printf(“socket is created”);
else
printf(“socket is not created”);
saddr.sin_family=AF_INET;
saddr.sin_port=htons(2500);
saddr.sin_addr.s_addr=htonl(INADDR_ANY);
b=bind(sd,(struct sockaddr*)&saddr,sizeof(saddr));
if(b==0)
printf(“binded successfully”);
else
printf(“binding failed’);
listen(sd,5);
cd=accept(sd,(struct sockaddr*)&caddr,&clen);
recv(cd,fname,sizeof(fnmae),0);
fp=open(fname,”w”);
fwrite(op,strlen(op),1,fp);
printf(“the file has been transferred”);
close(fd);
close(cd);
fclose(fp);
return 0;
}


//client
#include<string.h>
#include<sys/ioctl.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<net/if_arp.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb,h>
int main()
{
int sd,c,s;
char fname[50],sip[25],op[1000];
struct sockaddr_in caddr;
struct hostent *he;
FILE *fp;
printf(‘enter the server ip address”);
scanf(“%s”,sip);
he=gethostbyname(sip0;
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd!=1)
printf(“socket created”);
else
printf(“socket is not created’);
caddr.sin_family=AF_INET;
caddr.sin_port=htons(2500);
caddr.sin_addr=*((struct in_addr*)he->h_addr);
c=connect(sd,(struct sockaddr*)&caddr,sizeof(caddr));
if(c==0)
printf(“connected to server”);
else
printf(“connection failed”);
printf(“enter the file name’);
scanf(“%s”,fname);
send(sd,fname,sizeof(fname),0);
fp=fopen(fname,”r”);
fopen(op,1000,1,fp);
send(sd,op,sizeof(op),0);
fclose(fp);
close(sd);
return 0;
}