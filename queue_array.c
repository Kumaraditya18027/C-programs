#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int front,rear,n;
    int *a;
}queue;
void enqueue(queue *q,int x)
{
    q->rear++;
    q->a[q->rear]=x;
}
int dequeue(queue *q)
{
    q->front++;
    return q->a[q->front];
}
void display(queue q)
{
    int i=0;
    for(i=q.front+1;i<q.n;i++)
    {
        printf("%d ",q.a[i]);
    }
}
void delete(queue *q,int item)//for deleting at any position.
{
    int i,j=0,temp,x;
    for(i=0;i<q->n;i++)
    {
        if(item==q->a[i])
        {
            x=q->a[i];
            q->a[i]=-1;
            for(j=i+1;j<q->n;j++)
            {
                temp=q->a[i];
                q->a[i]=q->a[j];
                q->a[j]=temp;
            }
        }
        
    }
    q->n--;

    
}
void main()
{
    queue q;
    scanf("%d",&q.n);
    q.a=(int *)malloc(sizeof(int)*q.n);
    q.front=q.rear=-1;
    enqueue(&q,5);
    enqueue(&q,7);
    enqueue(&q,3);
    enqueue(&q,1);
    enqueue(&q,0);
    enqueue(&q,9);
   delete(&q,0);
    display(q);
    
}