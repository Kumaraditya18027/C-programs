#include<stdio.h>
#include<stdlib.h>
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
void dfs(int a,adj l)
{
    int i=a,j;
    static int visited[7];
    printf("%d ",i);
    visited[i]=1;
    for(j=1;j<=l.n;j++)
    {
        if(l.a[i][j]==1&&visited[j]==0)
        dfs(j,l);
    }
}

void main()
{
    adj l;int n;
    printf("Enter the no. of vertex\n");
    scanf("%d",&n);
    l.n=n+1;
    int i,j;
    l.a=(int **)malloc(sizeof(int*)*l.n);
    for(i=0;i<l.n;i++)
    {
        l.a[i]=(int*)malloc(sizeof(int)*l.n);
    }
    span(&l,n);
    printf("The adjecancy matrix is\n");
    adj_matrix(l);
    int a;
    printf("Enter the starting vertex\n");
    scanf("%d",&a);
    printf("The dfs traversal is ");
    dfs(a,l);
    
    
}
