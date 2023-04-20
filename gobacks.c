

#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;netinet/in.h&gt;
#include &lt;sys/socket.h&gt;
#include&lt;unistd.h&gt;
int main()
{
int sockfd, newSockFd, size, firstTime = 1, currentPacket, wait = 3;
char data[100], digit[2];
struct sockaddr_in client;
sockfd = socket(AF_INET, SOCK_STREAM,0);

client.sin_family = AF_INET;
client.sin_port = 3033;
client.sin_addr.s_addr = INADDR_ANY;

printf(&quot;\nStarting up...&quot;);
size = sizeof(client);
printf(&quot;\nEstablishing Connection to Server...&quot;);
connect(sockfd, (struct sockaddr *)&amp;client, size);

sprintf(data, &quot;REQUEST&quot;);
send(sockfd, data, strlen(data), 0); 
do
{
recv(sockfd, data, 100, 0);
currentPacket = atoi(data); 
printf(&quot;\nGot packet: %d&quot;, currentPacket);
if(currentPacket == 3 &amp;&amp; firstTime)
{ 
printf(&quot;\n*** Simulation: Packet data corrupted or incomplete.&quot;);
printf(&quot;\n*** Sending RETRANSMIT for packet 1.&quot;);
memset(&amp;data, 0, sizeof(data)); 
sprintf(data,&quot;R1&quot;); 
send(sockfd, data, strlen(data), 0);

firstTime =0;
}
else
{ wait--; 
if(!wait)
{
printf(&quot;\n*** Packet Accepted -&gt; Sending ACK&quot;);
wait = 3; 
sprintf(data, &quot;A&quot;);
digit[0] = (char)(currentPacket + 48); 
digit[1] = &#39;\0&#39;;

strcat(data, digit);
send(sockfd, data,strlen(data),0); 
}
}
}
while(currentPacket != 9);
printf(&quot;\nAll packets received...Exiting.&quot;);
close(sockfd);
return(0);
}
