/*A complete binary tree is having 0 or 2 child only,also known as strict or proper binary tree*/
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node* rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **a;
};
void create(struct queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->a=(struct node **)malloc(sizeof(struct node*)*q->size);
}
void enqueue(struct queue *q,struct node*p)
{
    if((q->rear+1)%q->size==q->front)
    printf("Queue is full\n");
    
  
else 
 {
    q->rear=(q->rear+1)%q->size;
    q->a[q->rear]=p;
 }
}
struct node* dequeue(struct queue *q)
{struct node *x=NULL;
if(q->rear==q->front)
 printf("Queue is empty\n");
else
{
    q->front=(q->front+1)%q->size;
    x=q->a[q->front];
    return x;
}
}
int isEmpty(struct queue q)
{
    return (q.rear==q.front);
}
//queue(for storing the adress of the nodes) creation ends, now tree creation begins;
struct node *root=NULL;
void tree_create()
{
    struct node *p,*t;
    int x; 
    struct queue q;
    create(&q,50);
    printf("Enter the root value\n");
    scanf("%d",&x);
    root=(struct node*)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child data of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter the right child data of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
        
    }
}
void preoder(struct node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preoder(p->lchild);
        preoder(p->rchild);
        
    }
}
void main()
{
    tree_create();
    preoder(root);
}