#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
void insert(int key)
{
    struct node *r=NULL,*p,*t=root;
    if(root==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
        return;
        else if(key>t->data)
        t=t->rchild;
        else
        t=t->lchild;
    }
     p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        if(p->data>r->data)
        r->rchild=p;
        else 
        r->lchild=p;
    
}
void preorder(struct node *p)
{
   if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int height(struct node *p)
{
    if(p==NULL)
    return 0;
    int x,y;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
    return x+1;
    else 
    return y+1;
    
}
struct node *Inpre(struct node*p)
{
    while(p&&p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}
struct node *Insucc(struct node*p)
{
    while(p&&p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}
struct node* delete(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
    return NULL;
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
         root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
    p->lchild=delete(p->lchild,key);
    else if(key>p->data)
    p->rchild=delete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild,q->data);
        }
        
        else
        {
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild,q->data);
        }
    }
    return p;
}
int main()
{
    printf("Enter how many value you want to insert\n ");
    int n;
    int a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value to be inserted\n");
        scanf("%d",&a);
        insert(a);
        printf("\n");
    }
    preorder(root);
    printf("Enter the element to be deleted\n");
    scanf("%d",&a);
    delete(root,a);
    preorder(root);
    return 0;
}