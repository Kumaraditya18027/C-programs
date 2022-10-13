#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int front,rear,n;
    int *a;
}queue;
void enqueue_r(queue *q,int x)
{
    q->rear++;
    q->a[q->rear]=x;
}
int dequeue_f(queue *q)
{
    q->front++;
    return q->a[q->front];
}
void enqueue_f(queue *q,int x)
{
    if(q->front==-1)
    {printf("cann't be inserted\n");
    return;
    }
    else
    {
     q->a[q->front]=x;
     q->front--;
    }
}
int dequeue_r(queue *q)
{
    int x;
    if(q->rear==-1)
    printf("can't be deleted\n");
    else
    {
        x=q->a[q->rear];
        q->rear--;
        return x;
    }
}
void display(queue q)
{
    int i=0;
    for(i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.a[i]);
    }
}
int main()
{
    queue q;
    scanf("%d",&q.n);
    q.a=(int *)malloc(sizeof(int)*q.n);
    q.front=q.rear=-1;
    enqueue_r(&q,5);
    enqueue_r(&q,7);
    enqueue_r(&q,3);
    enqueue_r(&q,1);
    dequeue_f(&q);
    enqueue_f(&q,0);
    dequeue_r(&q);
    display(q);
}