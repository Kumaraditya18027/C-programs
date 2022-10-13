#include<stdio.h>
#include<stdlib.h>
typedef struct queue 
{
    int f;int r;int *a;int n;
}qu;
void enqueue_fr(qu *q,int x)
{
    if((q->f==0&&q->r==q->n-1)||(q->f==q->r+1))
    {
        printf("queue is full\n");
    }
    else if(q->f==-1&&q->r==-1)
    {
        q->f=q->r=0;
        q->a[q->f]=x;
    }
    else if(q->f==0)
    {
        q->f=q->n-1;
        q->a[q->f]=x;
    }
    else
    {
        q->f--;
        q->a[q->f]=x;
    }
}
void enqueue_re(qu *q,int x)
{
    if((q->f==0&&q->r==q->n-1)||(q->f==q->r+1))
    printf("queue is full");
    else if(q->f==-1&&q->r==-1)
    {
        q->f=q->r=0;
        q->a[q->r]=x;
    }
    else if(q->r==q->n-1)
    {
        q->r=0;
        q->a[q->r]=x;
    }
    else
    {
        q->r++;
        q->a[q->r]=x;
    }
}
void dequeue_fr(qu *q)
{
    if(q->f==-1&&q->r==-1)
    printf("queue is empty\n");
    else if(q->r==q->f)//only one element present in queue(array).
    {
        printf("the deleted element is %d\n",q->a[q->f]);
        q->f=q->r=-1;
    }
    else if(q->f=q->n-1)
    {
        printf("%d \n",q->a[q->f]);
        q->f=0;
    }
    else 
    {
         printf("%d \n",q->a[q->f]);
         q->f++;
    }
}
void dequeue_rr(qu *q)
{
    if(q->f==-1&&q->r==-1)
    printf("queue is empty\n");
    else if(q->r==q->f)
    {
        printf("%d \n",q->a[q->r]);
        q->r=q->f=-1;
    }
    else if(q->r==0)
    {
        printf("%d \n",q->a[q->r]);
        q->r=q->n-1;
    }
    else 
    {
        printf("%d \n",q->a[q->r]);
        q->r--;
    }
    
}
void display(qu q)
{
    int i=q.f;
    while(i!=q.r)
    {
        printf("%d ",q.a[i]);
        i=(i+1)%q.n;
    }
    printf("%d ",q.a[q.r]);
}
void main()
{
    qu q;
    int n;
    scanf("%d",&q.n);
    q.a=(int*)malloc(sizeof(int)*q.n);
    q.f=q.r=-1;
    enqueue_fr(&q,2);
    enqueue_fr(&q,5);
    enqueue_fr(&q,7);
    enqueue_re(&q,3);
    enqueue_re(&q,1);
    dequeue_rr(&q);
    dequeue_fr(&q);
    display(q);
}