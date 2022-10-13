#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int size;
    int front,rear;
    int *a;
}queue;
void enqueue(queue *q,int x)
{
    if(q->rear==q->size-1)
    printf("queue full\n");
    else
    {
        q->rear++;
         q->a[q->rear]=x;
    }
}
int dequeue(queue *q)
{
    int x=-1;
    if(q->rear==q->front)//queue is empty.
    return x;
    else 
    {
        q->front++;
        x=q->a[q->front];
        return x;
    }
}
void display(queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.a[i]);
    }
    printf("\n");
}
void main()
{ 
    queue q;
    printf("Enter the size\n");
    scanf("%d",&q.size);
    q.front=q.rear=-1;
    q.a=(int*)malloc(sizeof(int)*q.size);
    enqueue(&q,4);
    enqueue(&q,7);
    printf("%d\n",dequeue(&q));
    display(q);

}