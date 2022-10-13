#include <stdio.h>
#include <stdlib.h>
typedef struct item
{
    int value;
    int priority;
} item;
int size = -1;
void enqueue(item *p, int value, int priority)
{
    size++;
    p[size].value = value;
    p[size].priority = priority;
}
void sort(item *p)
{
    int i, j, temp;
    item c;
    for (i = 1; i < size; i++)
    {
        temp = p[i].priority;
        c = p[i];
        j = i - 1;
        while (j >= 0 && p[j].priority > temp)
        {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = c;
    }
}
int dequeue(item *p)
{
    int temp = p[0].value;
    sort(p);
    for (int i = 1; i < size; i++)
    {
        p[i] = p[i + 1];
    }
    size--;
    return temp;
}
void disp(item *p)
{
    sort(p);
    for (int i = 0; i <= size; i++)
    {
        printf("Element %d  value is %d  priority %d \n", i + 1, p[i].value, p[i].priority);
    }
}
void main()
{
    item *p;
    int i, a, b, n;
    printf("Enter the size of the queue\n");
    scanf("%d", &n);
    p = (item *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the element and its priority\n");
        scanf("%d%d", &a, &b);
        enqueue(p, a, b);
    }
    printf("\n");
    disp(p);
}