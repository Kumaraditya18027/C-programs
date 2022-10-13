#include<stdio.h>
#include<stdlib.h>
typedef struct array
{
    int a[10];
    int length;
    int size;
}array;
int get(array *p,int index)
{
    if(index>=0&&index<p->length)
    return p->a[index];
}
void set(array *p,int index,int x)
{
    if(index>=0&&index<p->length)
    p->a[index]=x;

}
int max(array *p)
{
    int max;
    max=p->a[0];
    for(int i=1;i<p->length;i++)
    {
        if(p->a[i]>max)
        max=p->a[i];
    }
    return max;

}
int min(array *p)
{
    int min;
    min=p->a[0];
    for(int i=1;i<p->length;i++)
    {
        if(p->a[i]>min)
        min=p->a[i];
    }
    return min;
}
int sum(array *p)
{
    int sum=0;
    for(int i=0;i<p->length;i++)
    {
        sum+=p->a[i];
    }
    return sum;
}
int avg(array *p)
{
    int sum=0;
    for(int i=0;i<p->length;i++)
    {
        sum+=p->a[i];
    }
    return sum/p->length;
}
void swap(array *p,int i,int j)
{
    int temp=p->a[i];
    p->a[i]=p->a[j];
    p->a[j]=temp;
}
void reverse(array *p)
{
    int i=0,j=p->length-1;
    int temp;
    for(i,j;i<j;i++,j--)
    {
         temp=p->a[i];
         p->a[i]=p->a[j];
         p->a[j]=temp;
    }
}//roation likhna hai idhar abhi ata nahi

void append(array *p,int x)
{
    p->a[p->length]=x;
    p->length++;
}
void delete(array *p,int index)
{
    for(int i=index;i<p->length-1;i++)
    {
        p->a[i]=p->a[i+1];
    }
     p->length--;
}

void insert(array *p,int index,int n)
{ 
    int i=p->length;
    if(index>0 && index<=p->length)
    for(i=p->length;i>index;i--)
    {
        p->a[i]=p->a[i-1];
    }
    p->a[index]=n;
    p->length++;


}
void display(array p)
{
    int i;
    for(i=0;i<p.length;i++)
    {
        printf("%d",p.a[i]);
    }
}
void main()
{
   array a={{1,3,5,7,9},5,10};
   insert(&a,3,8);
   append(&a,0);
   delete(&a,4);
   display(a);
}