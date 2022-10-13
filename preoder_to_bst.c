#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
typedef  struct stack
{
    struct node* a[20];
    int top;
}stack;
void push(stack *st,struct node *x)
{
    st->a[++st->top]=x;
}
struct node* pop(stack *st)
{
    struct node* x;
    x=st->a[st->top--];
    return x;
}
int stacktop(stack *st)
{
    struct node *m;
    if(st->top)
    {
        m= st->a[st->top];
        return m->data;
    }
    else
    return 4936854;
}
void inorder(struct node* p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void create(int *a,int n)
{ stack st;
  st.top==-1;
  int i=0;
  struct node *t,*p;
  root=(struct node *)malloc(sizeof(struct node));
  root->data=a[i++];
  root->lchild=root->rchild=NULL;
  p=root;
  while(i<n)
  {
      t=(struct node*)malloc(sizeof(struct node));
      if(a[i]<p->data)
      {
          t->data=a[i++];
          t->rchild=t->lchild=NULL;
          p->lchild=t;
          push(&st,p);
          p=t;
      }
      else
      {
          if(a[i]>p->data&&a[i]<stacktop(&st))
          {
              t->data=a[i++];
              t->rchild=t->lchild=NULL;
              p->rchild=t;
              p=t;
          }
          else
          {
              p=pop(&st);
          }
          
      }
  }
  inorder(root);
  
    
}
void main()
{
    
    int a[8]={30,20,10,15,25,40,50,45};
    create(a,8);
    
}