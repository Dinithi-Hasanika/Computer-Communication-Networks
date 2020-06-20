#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char**argv)
{
int sockfd,n;
struct sockaddr_in servaddr;
char recvline[1000];

if (argc < 2)
{
printf("usage:  ./%s <IP address>\n",argv[0]);
return -1;
}else if(argc < 3){
printf("what do you want to echo?");
return -1;
}
int i;
int k=0;
printf("Received: ");
for(i =2;i< argc ;i++){

 

sockfd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr=inet_addr(argv[1]);
servaddr.sin_port=htons(32000);
sendto(sockfd,argv[i],strlen(argv[i])+1,0,(struct sockaddr
*)&servaddr,sizeof(servaddr));
n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
recvline[n]=0;
printf("%s ",recvline);

}
printf("\n");
return 0;
}
