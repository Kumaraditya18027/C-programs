#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *first=NULL;  
struct node *third=NULL;
struct node *second=NULL;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node*p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void rec_display(struct node *p)
{
   if(p!=NULL)
  {
     printf("%d ",p->data);
     rec_display(p->next);
  }
}
void reverse(struct  node*p)
{
    if(p!=NULL)
    {
        reverse(p->next);
        printf("%d ",p->data);
    }   
}
int count(struct node *p)
{
    if(p=0)
    return 0;
    else
    return count(p->next)+1;
}
int add(struct node *p)
{   
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int max(struct node*p)
{
    int max=-__INT32_MAX__;
    while(p)
    {
        if(p->data>max)
       {
             max=p->data;
             p=p->next;
       } 
        
    }
    return max;
    
}
struct node * search(struct node*p,int key)
{
    while(p)
    {
        if(key==p->data)
        return p;
        p=p->next;
    }
    return NULL;
}
void insert(struct node*p,int pos,int x)
{
    struct node*t;
    if(pos==0)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        int i=0;
        p=first;
        for(i=0;i<pos-1&&p;i++)
        p=p->next;
        if(p)
        { 
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

        }
    }
   //printf("hi");
}
int delete(struct node *p,int pos)
{
    struct node *q,*r;
    int x=-1,i;
    if(pos==1)
    {
        x=p->data;
        q=p;
        p=p->next;
        free(q);
    }
    else 
    {
       q=p;
       r=NULL;
       for(i=0;i<pos-1;i++)
       {
         r=q;
         q=q->next; 
       }
       if(q)
       {
         x=q->data;
         r->next=q->next;
         free(q);
       }
    }

}
void sorted_insert(struct node *p,int x)//problem
{
    struct node *q;
    q=NULL;
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(p==NULL)
    first=t;
    else
    {
     while(p&&p->data<x)
     {
        q=p;
        p=p->next;
     }
     if(p==first)
     {
        t->next=first;
        first=t;
     }
     else{
        t->next=q->next;
        q->next=t;
     }
    }

}
void remove_duplicate()
{
    struct node *p,*q;
    p=first;q=p->next;
    while(q!=NULL)
    {
        if(q->data!=p->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}


/*void create2(int a[],int n)
{
    int i;
    struct node *t,*last;
    second=(struct node*)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}*/

void merge(struct node*p,struct node *q)//requires two array and one more create function to create a second list//
{
    struct node*last;
    if(p->data<q->data) 
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
        
    }
    while(p &&q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        if(p)
        last->next=p;
        if(q)
        last->next=q;
    }
}



void main()
{
    int a[]={3,4,5,6,8};
    create(a,5);
    display(first);
   // printf("\n");
    //reverse(first);
    count(first);
    add(first);
    max(first);
   struct node *t= search(first,5);
    insert(first,2,7);
   // sorted_insert(first,7);
    display(first);
    //delete(first,3);                                            
}