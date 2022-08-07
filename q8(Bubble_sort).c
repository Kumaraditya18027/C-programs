#include<stdio.h>
#include<stdlib.h>
void input(int *,int);
void display(int *,int);
void buuble(int *,int);
void main()
{
    int *a,n;
    printf("Enter the no.of elements\n");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    input(a,n);
    printf("The aaray before sorting\n");
    display(a,n);
    buuble(a,n);
    printf("\nSorted array\n");
    display(a,n);
   
}
void input(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Element [%d]",i+1);
        scanf("%d",a+i);//why we need to take a+i, instead of a[i]//
    }
}
void display(int *a,int n)
{     int i;
      printf("\n");
      for(i=0;i<n;i++)
    printf(" %d ",a[i]);
}
void buuble(int *a,int n)
{
    int i,j,flag,t;
    for(i=0,flag=1;i<n-1&&flag;i++)
    {for(j=0,flag=0;j<n-i-1;j++)
     {   if(a[j]>a[j+1])//why can't we use *(a+j)//
      {     
            flag=1;
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
      }

     }

    }
}