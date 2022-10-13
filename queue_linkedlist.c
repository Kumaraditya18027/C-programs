#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {  t->data=x;
     t->next=NULL;
     if(front==NULL)
     {
        front=rear=t;
     }
     else
     {
        rear->next=t;
        rear=t;
     }
    }
}
int dequeue()
{
    int x=-1;
    struct node*p;
    p=front;
    if(front==NULL)//Queue is empty.
    printf("Queue is empty\n");
    else
    {
        front=front->next;
        x=p->data;
        free(p);
        return x;
    }
}
void display()
{
    struct node *p;
    p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void main()
{
    enqueue(3);
    enqueue(7);
    enqueue(9);
    dequeue();
    display();

}