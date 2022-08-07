#include<stdio.h>
#include<math.h>
#define MAX 10
void pascal(int);
void main()
{ int n;
  printf("Enter the no. of rows\n");
  scanf("%d",&n);
  pascal(n);
}
void pascal(int n)
{
    int r=0,i,j,k,c[MAX][MAX];
    for(j=0;j<n;j++)
    {
        printf("\n");
        for(i=1;i<n-j;i++)
        {
            printf(" ");
        }
        for(r=0;r<=j;r++)
        {
            c[j][r]=(r==0||r==j)?1:c[j-1][r-1]+c[j-1][r];
            printf(" %d",c[j][r]);
        }
    }
}