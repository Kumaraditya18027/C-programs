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
    if((q->rear+1)%q->size==q->front)
    printf("queue full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
         q->a[q->rear]=x;
    }
}
int dequeue(queue *q)
{
    int x=-1;
    if(q->rear==q->front)//queue empty
    return x;
    else 
    {
        q->front=(q->front+1)%q->size;
        x=q->a[q->front];
        return x;
    }
}
void display(queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.a[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}
void main()
{ 
    queue q;
    printf("Enter the size\n");
    scanf("%d",&q.size);
    q.front=q.rear=0;
    q.a=(int*)malloc(sizeof(int)*q.size);
    enqueue(&q,4);
    enqueue(&q,7);
    enqueue(&q,9);
    printf("%d\n",dequeue(&q));
    display(q);

}