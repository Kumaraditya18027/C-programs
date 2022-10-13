#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    int *c;
    int n;
    
}board;
void intialisation(board *b,int n)
{
    b->c=(int *)malloc(sizeof(int)*(n+1));
    
    int i;
    for(i=1;i<=n;i++)
    b->c[i]=-1;
    b->n=n;
}
void display(board b,int n,int* count)
{
    int i,j;
    printf("Solution %d",++(*count));
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
        {
            if(b.c[i]==j)
            printf(" Q ");
            else
            printf(" x ");
        }
    }
    printf("\n");
}
int is_safe(board b,int x,int y)
{
    int i;
    for(i=1;i<x;i++)
    {
        if(b.c[i]==y||abs(x-i)==abs(y-b.c[i]))
        {
            return 0;
        }
    }
    return 1;
}
void queen(board *b,int k,int n,int *count)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(is_safe(*b,k,j))
        {
            b->c[k]=j;
            if(k==n)
            display(*b,n,count);
            else
            queen(b,k+1,n,count);
        }
    }
}
void main()
{
    int n;
    int count=0;
    board *b;
    b=(board*)malloc(sizeof(board));
    printf("Enter no.of queen\n");
    scanf("%d",&n);
    intialisation(b,n);
    queen(b,1,n,&count);
}
