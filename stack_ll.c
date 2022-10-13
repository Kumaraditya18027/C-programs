#include<stdio.h>
#include<stdlib.h>
 struct node 
{
    int data;
    struct node *next;
};
 struct node *top=NULL;
void push(int x)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Stack overflow\n");
    else
    {
     t->data=x;
     t->next=top;
     top=t;
    }   
}
int pop()
{
    struct node *p;
    int x=-1;
    if(top==NULL)
    printf("Underflow\n");
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}
int peek(int pos)
{
    struct node *p=top;
  int i;
  for(i=1;i<pos&&p!=NULL;i++)
  {
     p=p->next;
  }
  if(p)
  return p->data;
  else 
  return -1;
}
int stacktop()
{
    if(top)
    return top->data;
    else 
    return -1;
}
int isfull()
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    int r;
    if(t==NULL)
    r= 1;
    else 
    r= 0;
    free(t);
    return r;
}
int isempty()
{
    if(top==NULL)
    return 1;
    else 
    return 0;// return top?0:1
}
void display()
{
    struct node *p=top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void main()
{
   int x,y,z;
   push(3);
   push(2);
   push(1);
   push(9);
   display();
   printf("\n%d",peek(2));
   printf("\n%d",pop());
   printf("\n%d",peek(2));

}