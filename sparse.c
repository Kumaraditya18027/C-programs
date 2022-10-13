#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
    int i;
    int j;
    int x;
}elem;
typedef struct sparse
{
    int m;
    int n;
    int num;
    elem *e;
}sparse;
void create(sparse *s)
{
    int i;
    printf("Enter the dimension\n");
    scanf("%d %d",&s->m,&s->n);
    printf("The toal number of non zero element\n");
    scanf("%d",&s->num);
    s->e=(elem*)malloc(sizeof(elem)*s->num);
    
    printf("Enter all elements\n");
    for(i=0;i<s->num;i++)
    {
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}
//void transpose(sparse *s)
//{
     //int i,j,k=0;
       // for(i=0;i<s->m;i++)
       // {
        //    for(j=0;j<s->n;j++)
          //  {
            //    if(s->e[k].i==i &&s->e[k].j==j)
              //  {
                //    printf("%d ",s.e[k++].x);
                //}
                //else
                //printf("0 ");
            //}
           // printf("\n");
        //}
    //}//
    
//}
void trans(sparse *s)
{
    int temp;
    elem t,p;
    int j;
    for(int i=0;i<s->num;i++)
    {
       temp=s->e[i].i;
       s->e[i].i=s->e[i].j;
       s->e[i].j=temp;
    }
    for(int j=0;j<s->num-1;j++)
    {
        if(s->e[j].i>s->e[j+1].i)
        {
          t=s->e[j];
          s->e[j]=s->e[j+1];
          s->e[j+1]=t;     
        }
        else if(s->e[j].i==s->e[j+1].i)
        {
            if(s->e[j].j>s->e[j+1].j)
           {
             p=s->e[j];
            s->e[j]=s->e[j+1];
            s->e[j+1]=p;
           }
        }

    }


}
void display(sparse s)
    {
        int i,j,k=0;
        for(i=0;i<s.m;i++)
        {
            for(j=0;j<s.n;j++)
            {
                if(s.e[k].i==i &&s.e[k].j==j)
                {
                    printf("%d ",s.e[k++].x);
                }
                else
                printf("0 ");
            }
            printf("\n");
        }
    }
void display1(sparse s)
    {
        int i,j,k=0;
        for(i=0;i<s.n;i++)
        {
            for(j=0;j<s.m;j++)
            {
                if(s.e[k].i==i &&s.e[k].j==j)
                {
                    printf("%d ",s.e[k++].x);
                }
                else
                printf("0 ");
            }
            printf("\n");
        }
    }

void main()
{
    sparse s;
    create(&s);
    display(s);
    trans(&s);
    printf("The transpose is:\n");
    display1(s);
}