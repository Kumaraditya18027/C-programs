#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int *a;
    int front,rear,n;
}queue;
typedef struct adj
{
    int **a;
    int n;
}adj;
void span(adj *l,int n)
{
    int org,destin;
    int i,j,count,max;
    max=n*(n-1);
    for(i=1;i<=max;i++)
    {
        printf("Enter the origin and destination of edge %d \n",i);
        scanf("%d%d",&org,&destin);
        if(org==-1&&destin==-1)
        break;
        if(org>n||destin>n||org<0||destin<0)
        {
            printf("Invalid index\n");
            i--;
        }
        else
        l->a[org][destin]=1;
    }
}
void adj_matrix(adj l)
{
    int i,j;
    for(i=1;i<l.n;i++)
    {
        for(j=1;j<l.n;j++)
        {
            if(l.a[i][j]==1)
            printf("1");
            else
            printf("0");
        }
        printf("\n");
    }
}
void enqueue(queue *q,int n)
{
    q->a[++q->rear]=n;
}

int dequeue(queue *q)
{
    int x;
    x=q->a[++q->front];
    return x;
}
int isEmpty(queue *q)
{
    return (q->front==q->rear)?1:0;
}
void bfs(int a,adj l,queue *q)
{
    int visited[7]={0};
    int i=a,j,k;
    printf("%d ",i);
    visited[i]=1;
    enqueue(q,i);
    while(isEmpty(q)!=1)
    {
        j=dequeue(q);
      for(k=1;k<l.n;k++)
     { 
        if(l.a[j][k]==1&&visited[k]==0)
        {
            printf("%d ",k);
            visited[k]=1;
            enqueue(q,k);
        }
    }
    }
}
void main()
{
    adj l;int n,a;
    queue q;
    q.front=q.rear=-1;
    printf("Enter the no. of vertex\n");
    scanf("%d",&n);
    l.n=n+1;
    q.a=(int*)malloc(sizeof(int)*n+1);
    int i,j;
    l.a=(int **)malloc(sizeof(int*)*l.n);
    for(i=0;i<l.n;i++)
    {
        l.a[i]=(int*)malloc(sizeof(int)*l.n);
    }
    span(&l,n);
    printf("The adjecancy matrix is\n");
    adj_matrix(l);
    printf("Enter the starting vertex\n");
    scanf("%d",&a);
    printf("The Bfs traversal is ");
    bfs(a,l,&q);
    
    
}
