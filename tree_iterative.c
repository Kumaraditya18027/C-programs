#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
typedef struct queue
{
    int size;int front;int rear; struct node **a;
    
}queue;
typedef struct stack 
{
    int top;
    int n;
    struct node **s;
}stack;
void create(queue *q,int n)
{
    q->size=n;
    q->front=q->rear=-1;
    q->a=(struct node**)malloc(sizeof(struct node)*q->size);
}
void enqueue(queue *q,struct node *p)
{
    if((q->rear+1)%q->size==q->front)
    printf("Queue is full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->a[q->rear]=p;
    }
}
struct node *dequeue(queue *q)
{
    struct node* x=NULL;
    if(q->front==q->rear)
    printf("Queue is empty\n");
    else
    {  
       q->front=(q->front+1)%q->size;
       x=q->a[q->front];
       return x;
    }
}
int isEmpty(queue *q)
{
    return (q->front==q->rear);
}
void create_stack(stack *st,int n)
{
    st->top=-1;
    st->n=n;
    st->s=(struct node **)malloc(sizeof(struct node)*st->n);
}
void push(stack *st,struct node *p)
{
    st->s[++st->top]=p;
}
struct node *pop(stack *st)
{
    struct node *s;
    s=st->s[st->top--];
    return s;
}
int isempty(stack st)
{
    if(st.top==-1)
    {
        return 1;
        
    }
    else 
    return 0;
}
void preoder(struct node *p)
{
    stack st;
    create_stack(&st,20);
    while(p!=NULL||!(isempty(st)))
    {
       if(p!=NULL)
    {
        printf("%d ",p->data);
        push(&st,p);
        p=p->lchild;
    }
    else
    {
        p=pop(&st);
        p=p->rchild;
    }
    }
    
}
//void postorder(struct node *p)
//{
//    stack st;
//    create_stack(&st,20);
//    //long int temp;
//    while(p!=NULL||!(isempty(st)))
//    {
//        if(p)
//        {
//            push(&st,p);
//            p=p->lchild;
//        }
//        else
//        {
//            p=pop(&st);
//            p=p->rchild;
//            if(p==NULL)
//            printf("%d",p->data);
//        }
//    }
//}
void level_order(struct node* p)
{
    queue q;
    create(&q,30);
    printf("%d  ",p->data);
    enqueue(&q,p);
    while(!isEmpty(&q))
    {
        p=dequeue(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}
int count(struct node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    else
    return 0;
}
int sum(struct node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+p->data;
    }
    else
    return 0;
}
int height(struct node *p)
{
    int x,y;
    if(p)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
        return x+1;
        else
        return y+1;
        
    }
    else
    return 0;
}
int leaf(struct node *p)
{
    int x,y;
    if(p)
    {
        x=leaf(p->lchild);
        y=leaf(p->rchild);
        if(p->lchild==NULL&&p->rchild==NULL)
        return x+y+1;
        else 
        return x+y;
    }
    else
    return 0;
}
void tree_create()
{
    struct node *root=NULL;
    int x;
    struct node *p,*t;
    queue q;
    create(&q,30);
    printf("Enter the root value\n");
    scanf("%d",&x);
    root=(struct node*)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(&q))
    {
        p=dequeue(&q);
        printf("Enter the L child of %d \n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
         printf("Enter the R child of %d \n",p->data);
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
    level_order(root);
    printf("THE NO.OF NODES IN THE TREE IS %d \n",count(root));
    printf("The sum of the nodes is %d \n",sum(root));
    printf("The height of the tree is height %d \n",height(root));
    printf("The no. of leaf nodes are %d \n",leaf(root));//for leaf nodes
    
}
void main()
{
    queue q;
    create(&q,30);
    tree_create();
}