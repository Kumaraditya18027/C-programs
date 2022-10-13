#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void create(int a[],int n)
{
    int i=0;
    struct node*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        struct node* t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }


}
void display()
{
    struct node *p=head;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}
void survivor(struct node **head,int k)
{
   int i;
   struct node *p,*q;
   p=q=*head;
   while(p->next!=p)
   {
      for(i=1;i<k;i++)
     {
         q=p;
         p=p->next;
     }
     q->next=p->next;
     free(p);
     p=q->next;
  }
  *head=p;
  printf("\nThe survivor is %d ",p->data);
}

void main()
{
    int n,i;
    int a[20];
    printf("Enter the elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter elements\n");
        scanf("%d",&a[i]);
    }
    int k;
    printf("How many number will be skipped\n");
    scanf("%d",&k);
    
    create(a,n);
    display();
    survivor(&head,k);


}