#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(char *[], int,int);
void swap(char *[], int, int);
void main()
{
    int i;
    char *names[] = {"Aditya", "Anmol", "shubham", "solam", "dinesh", "rohan"};
    printf("Names before sorting\n");
    for (i = 0; i < 6; i++)
    {
        printf("\n%s", names[i]);
    }
    sort(names,0,5);
    printf("\nNames after sorting\n");
    for (i = 0; i < 6; i++)
    {
        printf("\n%s", names[i]);
    }
}
void sort(char*v[],int l,int r)
{
    int i,last;
    int mid=(l+r)/2;
    if(l>=r)
        return;
    last=l;
    swap(v,l,mid);
    for(i=l+1;i<=r;i++)
    {
       if(strcmpi(v[i],v[l])<0)
       {
           swap(v,++last,i);
       }
    }
    swap(v,last,l);
    sort(v,l,last-1);
    sort(v,last+1,r);
}
void swap(char *v[],int i,int j)
{
    char *t=v[i];
    v[i]=v[j];
    v[j]=t;
}

