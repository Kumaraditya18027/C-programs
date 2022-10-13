#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*front=NULL,*rear =NULL;
void enqueue(int n)
{
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    printf("The queue is full\n");
    else
    {
        t->data=n;
        t->next=NULL;
        if(front=NULL)
        front=rear=t;
        else
        {
            rear=rear->next;
            rear=t;
        }
    }
}
int dequeue()
{
    int x=-1;
    struct node*t;
    if(front==NULL)
    {
        printf("Queue is empty\n");
           return x;   
    }
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
       
    }
     return x;
}
int isEmpty()
{
    return front==NULL;
}
void bfs(int g[][7],int start,int n)
{
    int i=start,j;
    int visited[7]={0};
    printf("%d",i);
    visited[i]=1;
    enqueue(i);
    while(!isEmpty())
    {
         i=dequeue();
       for( j=1;j<n;j++)
       {
           if(g[i][j]==1&&visited[j]==0)
           {
               printf("%d",j);
               visited[j]=1;
               enqueue(j);
           }
           
       }
    }
    
}
void dfs(int g[][7],int start,int n)
{
    int i=start;
    static int visited[7]={0};
    if(visited[i]==0)
    {
        printf("%d",i);
        visited[i]=1;
    }
    for(int v=1;v<n;v++)
    {
        if(g[i][v]==1&&visited[v]==0)
        {
            dfs(g,v,n);
        }
    }
}
int main()
{
 int g[7][7]={{0,0,0,0,0,0,0},
              {0,0,1,1,0,0,0},
              {0,1,0,0,1,0,0},
              {0,1,0,0,1,0,0},
              {0,0,1,1,0,1,1},
              {0,0,0,0,1,0,0},
              {0,0,0,0,1,0,0}};
  //dfs(g,4,7);
   bfs(g,4,7);
  return 0;
}
