#include<stdio.h>
void display(int *,int);
void input(int *,int);
int binarysearch(int *,int ,int, int);
void main()
{
    int l,r,n,x;
    int a[10];
    printf("Enter the array size\n");
    scanf("%d",&n);
    input(a,n);//the array needs to be sorted//
    display(a,n);
    l=0;
    r=n-1;
    printf("\nEnter the digit to be found\n");
    scanf("%d",&x);
    printf("The index of the number is %d\n",binarysearch(a,l,r,x));
}
void input(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Element [%d]",i+1);
        scanf("%d",&a[i]);
    }
}
void display(int *a,int n)
{     int i;
      printf("\n");
      for(i=0;i<n;i++)
       {printf(" %d ",a[i]);}
}
int binarysearch(int *a,int l,int r, int x)//This works for ascending order only//
{ 
   int mid=(l+r)/2;
   if(l>r)
   {
       return -1;
   }
   if(a[mid]==x)
   {
       return mid;
   }
   else if(a[mid]>x)//we need to change this we need to change the condition to < if we need the value for decreasingly sorted array(descending order)//
   {
       return binarysearch(a,l,mid-1,x);
   }
   else{
        return binarysearch(a,mid+1,r,x);
   }

}