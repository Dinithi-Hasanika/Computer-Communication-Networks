#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char**argv)
{
int sockfd,n;
struct sockaddr_in servaddr, cliaddr;
socklen_t len;
char mesg[1000];char* banner = "Hello UDP client! This is UDP server";
sockfd=socket(AF_INET,SOCK_DGRAM,0);
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(32000);
bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
len = sizeof(cliaddr);
while(1){
n = recvfrom(sockfd,mesg,1000,0,(struct sockaddr *)&cliaddr,&len);
//char * temp = NULL;
while(1){
sleep(1);
time_t mytime = time(NULL);

char * time_str = ctime(&mytime);

time_str[strlen(time_str)-1] = '\0';



sendto(sockfd,time_str,n,0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
}



}
return 0;
}

