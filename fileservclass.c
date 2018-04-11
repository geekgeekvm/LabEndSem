//serv
main(int argc,char **argv)
{
int i,j;
ssize_t n;
FILE *fp;
char s[80],f[80];
struct sockaddr_in
servaddr,cliaddr;
int listenfd,connfd,clilen;
listenfd=socket(AF_INET,SOCK_STREA
M,0);
bind(listenfd,(struct sockaddr
*)&servaddr,sizeof(servaddr));
listen(listenfd,1);
clilen=sizeof(cliaddr);
connfd=accept(listenfd,(struct
sockaddr*)&cliaddr,&clilen);
printf("\n client connected");
read();
fp=fopen(f,"r");

printf("\n name of the file:
%s",f);
while(fgets(s,80,fp)!=NULL)
{
printf("%s",s);
write();
}
close(listenfd);
fclose(fp); }

//cli
main(int argc,char **argv)
{
int i,j;
ssize_t n;
char filename[80],recvline[80];
struct sockaddr_in servaddr;
int sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,
0);
inet_pton(AF_INET,argv[1],&servadd
r.sin_addr);
connect(sockfd,(struct
sockaddr*)&servaddr,sizeof(servadd
r));
printf("enter the file name");
scanf("%s",filename);
write();
printf("\n data from server: \n");

while(read()!=0)
{
fputs(recvline,stdout);
}
close(sockfd);
}

/***Compilation of client
$gcc fileclient.cc –o cli
Compilation of server
$gcc fileserver.cc –o ser

Execution of server: $./ser
Execution of client: $./cli
localhost***/
