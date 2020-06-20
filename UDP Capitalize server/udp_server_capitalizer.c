#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>




int main(int argc, char**argv)
{
int sockfd,n;
struct sockaddr_in servaddr, cliaddr;
socklen_t len;
char mesg[1000];

char* banner = "ack";
sockfd=socket(AF_INET,SOCK_DGRAM,0);
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(32000);
bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
len = sizeof(cliaddr);

while(1){

  n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
  sendto(sockfd,banner,1000,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));

  int sentences = atoi(mesg);
  mesg[n] = 0;
  printf("Received: %s\n",mesg);

  int i;
  for(i=0;i< sentences;i++){

  n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);

  mesg[n] = 0;
  printf("Received: %s\n",mesg);

  char newMesg[n] ;
  strcpy(newMesg,mesg);
  
  int j;
  for(j=0;j< n;j++){

  if(newMesg[j]>= 97 && newMesg[j]<= 122 ){

  newMesg[j] = newMesg[j] - 32 ;
  }
 }

sendto(sockfd,(char*)newMesg,n,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
}
}
return 0;
}
