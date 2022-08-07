#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
    int r,c;
    int a[MAX][MAX];
}matrix;
void input(matrix *);
void disp(matrix);
matrix add(matrix,matrix);
void main()
{
    matrix m1,m2,r;
    printf("Enter the  first matrix\n");
    input(&m1);
    printf("\n");
    disp(m1);
    printf("\nEnter the  first matrix\n");
    input(&m2);
    printf("\n");
    disp(m2);
    r=add(m1,m2);
    printf("\nThe resultant matrix :\n");
    disp(r);
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
matrix add(matrix m1, matrix m2)
{
    int i,j;
    matrix t;
    if(m1.r!=m2.r||m1.c!=m2.c)
    {
        printf("Addition not possible\n");
    }
    t.r=m1.r;
    t.c=m1.c;
    for(i=0;i<t.r;i++)
    {
        for(j=0;j<t.c;j++)
        {
            t.a[i][j]=m1.a[i][j]+m2.a[i][j];
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
