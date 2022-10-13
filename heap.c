#include<stdio.h>
#include<stdlib.h>
void insert(int a[],int n)
{
    int i=n,temp;
    temp=a[n];
    while(i>1&&temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
int delete(int a[],int n)
{
    int i,j,x,val,temp;
    val=a[1];
   
    a[1]=a[n];
    a[n]=val;//adding value at the end of the array, resulting in heap sort.
    i=1;j=2*i;
    while(j<n-1)
    {
        if(j<n-1&&a[j+1]>a[j])
        j=j+1;
        if(a[i]<a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else
        break;
        return val;
        
    }
}
void main()
{
    int i=0;
    int a[]={0,2,5,7,8,1};
    for( i=2;i<=5;i++)
    insert(a,i);
    for(i=5;i>1;i--)
    delete(a,i);//heap sort.
    for(i=1;i<=5;i++)
    {
        printf("%d ",a[i]);
    }

}