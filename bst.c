#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * lchild;
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
void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
        
    }
}
struct node* search(struct node *p,int key)
{
    
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;
    else if (key<p->data)
    return search(p->lchild,key);
    else
    return search(p->rchild,key);
    
}
void main()
{
    struct node *t;
    insert(88);
    insert(45);
    insert(7);
    insert(29);
    t=search(root,3);
    if(t)
    printf("Element is found and it is %d \n",t->data);
    else 
    printf("Element is not found\n");
    inorder(root);
    
}