#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<time.h>
#include<netinet/in.h>
#define S_PORT 43454
#define C_port 43455
#define ERROR-1
#define IP_STR "127.0.0.1"
int main(int argc,char const *argv[]){
 int std;
 int num=1;
 time_t start_time ,rtt,current_time;
 struct sockaddr_in servaddr,client addr;
 socklen_t_addrlen;
 std=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP)
 if (std==ERROR){
     perror("Could not opne a socket");
      return 1;
  }
memset((char*) &servaddr,0,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s=inet_addr(IP_STR)
memset((char *) &clientaddr,0,sizeof(clientaddr));
clientaddr.sin_family=AF_INET;
clientaddr.sin_addr.s_addr=inet(IP_STR);
if (bind(std,(struct sockaaddr *) &clientaddr,sizeof(clientaddr)))!=0){
perror("couldnot bind socket");
return 2;
}
printf("client is running on %s:%d",IP_STR,C_PORT);
start_time =time(NULL);
sendto(std,&num,sizeof(num),0,(struct sockaddr*)& clientaddr,&addrlen);p
rtt=time(null)-starttime;
current_time+=rtt/2;
printf("server time :%s " ctime(&currenttime));
return 0;
}
