#include<stdio.h>
#include<string.h>

#include<unistd.h>
#include<netinet/in.h>
int main()
{
     int k,sock_desc,temp_sock_desc;
     char buf[100];
     socklen_t len;
     struct sockaddr_in server,client;
     sock_desc=socket(AF_INET,SOCK_STREAM,0);
     if (sock_desc==-1)
     {
        printf("ERROR IN SOCKET CREATION");
     }
     
     server.sin_family=AF_INET;
     server.sin_addr.s_addr=INADDR_ANY;
     server.sin_port=3003;
     client.sin_family =AF_INET;
     client.sin_addr.s_addr=INADDR_ANY;
     client.sin_port=3003;
     k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
     if(k==-1)
     {
         printf("error in binding");
     }
     printf("BINDED\n");
     k=listen(sock_desc,5);
     if (k==-1)
     {
      printf("EEROR in listening");
     }
         
         len=sizeof(client);
         temp_sock_desc=accept(sock_desc,(struct sockaddr*)&client,&len);
         if (temp_sock_desc==-1)
         {
            printf("ERROR in temp socket creation");
         }
         k=recv(temp_sock_desc,buf,100,0);
         if (k==-1)
         {
         
           printf("ERROR in Recieving");
         }
         int n=atoi(buf);
         int i,fact=1;
         for(i=1;i<=n;i++)
         {
         
           fact=fact*i;
         }
         printf("Factorial of number sent from client is %d\n",fact);
         close(temp_sock_desc);
         return 0;
}                
