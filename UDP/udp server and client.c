server:
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main(int argc,char *argv[])
{
  struct sockaddr_in server,client;
  if (argc!=2)
   printf("INPUT FORMAT NOT CORRECT ");
   
   int sockfd=socket(AF_INET,SOCK_DGRAM,0);
   if (sockfd==-1)
   printf("ERROR IN socket()");
   server.sin_family=AF_INET;
   server.sin_addr.s_addr=INADDR_ANY;
   server.sin_port=htons(atoi(argv[1]));
   if (bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
   
   printf("EEROR IN BIND");
   char buffer[100];
   socklen_t server_len=sizeof(server);
   printf("SERVER IS WAITING\n");
   if (recvfrom(sockfd,buffer,100,0,(struct sockaddr *)&server,&server_len)<0)
   printf("ERROR IN recvfrom()!");
   printf("Got a datagram %s",buffer);
   return 0;
 } 
 
 client:
 #include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main(int argc,char *argv[])
{
  struct sockaddr_in server,client;
  if (argc!=3)
   printf("INPUT FORMAT NOT CORRECT ");
   
   int sockfd=socket(AF_INET,SOCK_DGRAM,0);
   if (sockfd==-1)
   printf("ERROR IN socket();");
   server.sin_family=AF_INET;
   server.sin_addr.s_addr=INADDR_ANY;
   server.sin_port=htons(atoi(argv[2]));
   char buffer[100];
   printf("Enter a message to server");
   fgets(buffer,100,stdin);
   if(sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr *)&server,sizeof(server))<0)
   printf("ERROR IN SENDTO");
   return 0;
   
}
