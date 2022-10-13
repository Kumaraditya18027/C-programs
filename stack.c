#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*top=NULL;
void push(struct node *top,int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Satck is full\n");
    else
    {
          t->data=x;
          t->next=top;
          t=top;
    }
}
int pop(struct node* top)
{
    struct node *p;
    int x=-1;
    if(p==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        p=top;
        x=p->data;
        top=top->next;
        free(p);
    }
    return x;
}
int peek(struct node*top,int pos)
{
     struct node *p=top;
     int i;
     if(p)
     {
        for(i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        return p->data;
     }
     else return -1;
}
int isEmpty(struct node *top)
{
    return top?0:1;
}
int isFull(struct node*top)
{
    struct node*t=(struct node*)malloc(sizeof(struct node));
    return t?0:1;
}
int stackTop9(struct node *top)
{
    if(top)
    return top->data;
    else
    return -1;
}
void display(struct node*top)
{
    struct node *p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void main()
{ 
    int x,y,z;
    int ch;
    printf("1 for push\n2for pop\n3 for peek\n4 for empty check\n5 for full check\n6 for finding the data at stack top\n0 for exit\n");
    do
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:break;
            case 1:printf("Enter the value\n");
                  scanf("%d",&x);
                  push(top,x);
                  break;
            case 2:z=pop(top);
                   printf("The pooped element is %d\n",z);
                   break;
            default :printf("Wrong choice\n");

        }

    }while(ch!=0);
    display(top);
}