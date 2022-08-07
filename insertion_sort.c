#include<stdio.h>
#include<stdlib.h>
void input(int *,int );
void display(int *,int);
void insertion(int *,int);
void main()
{
    int *a,n;
    printf("Enter the no.of elements\n");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    input(a,n);
    printf("The aaray before sorting\n");
    display(a,n);
    insertion(a,n);
    printf("\nSorted array\n");
    display(a,n);
   
}
void input(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Element [%d]",i+1);
        scanf("%d",&a[i]);//why we need to take a+i, instead of a[i]//
    }
}
void display(int *a,int n)
{     int i;
      printf("\n");
      for(i=0;i<n;i++)
       {printf(" %d ",a[i]);}
}
void insertion(int *a, int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
