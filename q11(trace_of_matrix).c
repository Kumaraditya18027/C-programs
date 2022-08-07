#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
    int r,c;
    int a[MAX][MAX];
}matrix;
void input(matrix *);
void disp(matrix);
int trace(matrix);
void main()
{
    matrix m1;
    printf("Enter the matrix\n");
    input(&m1);
    printf("\n");
    printf("The trace of the matrix is %d\n",trace(m1));
}
void input(matrix *m1)
{
    int i,j;
    printf("Enter the no. of rows\n");
    scanf("%d",&m1->r);
    printf("Enter the no. of columns\n");
    scanf("%d",&m1->c);
    for(i=0;i<m1->r;i++)
    {
        for(j=0;j<m1->c;j++)
        {
            printf("Enter the element[%d][%d]",i+1,j+1);
            scanf("%d",&m1->a[i][j]);
        }
    }
}
int trace(matrix m1)//not giving correct result//
{
    int i,j,t;
    t=0;
    for(i=0;i<m1.r;i++)
    {
        for(j=0;j<m1.c;j++)
        {  
            if(i=j)
            {
                t=t+m1.a[i][j];
            }
            
        }
    }
    return t;
    
}
void disp(matrix m1)
{
    int i,j;
    for(i=0;i<m1.r;i++)
    {   printf("\n");
        for(j=0;j<m1.c;j++)
        {
            printf(" %d ",m1.a[i][j]);
        }
    }
}
