#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
int main()
{
     int k,sock_desc;
     char buf[100];int R;
     struct sockaddr_in client;
     sock_desc=socket(AF_INET,SOCK_STREAM,0);
     if (sock_desc==-1)
     {
        printf("ERROR IN SOCKET CREATION");
     }
     
     client.sin_family =AF_INET;
     client.sin_addr.s_addr=INADDR_ANY;
     client.sin_port=3003;
     R=connect(sock_desc,(struct sockaddr*)&client,sizeof(client));
     if (R==-1)
     {
         printf("ERROR IN CONNECTING TO SERVER");
     } 
     printf("ENTER THE DATA TO BE SENT");
     fgets(buf,100,stdin);
     R= send(sock_desc,buf,100,0);
     if (R==-1)
     {
       printf("ERROR IN SENDING DATA TO SERVER..");
     }
     printf("DATA SEND");
     close(sock_desc);
     return 0;  
}     
