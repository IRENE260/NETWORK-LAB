#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Link{
  int hop,dest,wt;
  };
  struct network{
  int H,L;
  struct Link*link;
  };
  void main()
  {
      int H,L,s,i,j,dist[H],wt;
      printf("Distance vector routing\n Enter the number of hops\n");
      scanf("%d",&H);
      printf("Enter the number of links");
      scanf("%d",&L);
     struct network* n=(struct network*)malloc(sizeof(struct network));
      n->link=(struct Link*)malloc (n->L * sizeof(struct Link));
      for(i=0;i<L;i++)
      {
           printf("\n Link %d Enter the source,destination ,weight",i+1);
           scanf("%d",&n->link[i].hop);
           scanf("%d",&n->link[i].dest);
           scanf("%d" ,&n->link[i].wt);
           
           
           for(i=0;i<H;i++)
           {
              dist[i]=INT_MAX;
              dist[s]=0;
              for(i=1;i<H;i++)
              {
                for(j=0;j<i;j++)
                {
                    int u=n->link[j].hop;
                    int v=n->link[j].wt;
                    if(dist[u]+wt<dist[v])
                    {
                       dist[v]=dist[u]+wt;
                    }
                    
                    
                }
                
              }
              
              
              }
              
              
          for(i=0;i<L;i++)
          {
               int u=n->link[i].hop;
               int v=n->link[i].dest;
               int wt=n->link[i].wt;
               if(dist[u]+wt<dist[v])
               {
                     printf("Network contains -ve weight cycle");
               }
               printf("\nHOP \t Distance from source \n");
               for(i=0;i<H;i++)
               {
                   printf("%d\t%d\n",i,dist[i]);
                   
               }
           }
    }                            
                    
 }                   
                    
