#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    int coeff;
    int expo;
}element;
typedef struct
{
    int n;
    element *e;
}poly;
void create(poly *p)
{
    printf("Enter the total no. of no. of zero elements int the polynomial\n");
    scanf("%d",&p->n);
    p->e=(element *)malloc(sizeof(element)*p->n);
    printf("Enter the polynomials terms\n");
    for(int i=0;i<p->n;i++)
    {
        printf("Term no. %d\n",i+1);
        scanf("%d %d",&p->e[i].coeff,&p->e[i].expo);
    }
    //for evaluation at any value of x;
   // printf("Enter any value of x\n");
    //int x,sum=0;
    //scanf("%d",&x);
    //for(int j=0;j<p.n;j++)
    //{
      //  sum+=p.e[j].coeff*pow(x,p.e[j].expo);
    //}
    //printf("The value of the expression is %d\n",sum);//


 
}
void display(poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    printf("%dx%d+",p.e[i].coeff,p.e[i].expo);
    printf("\n");
}
poly* add(poly *p1,poly *p2)
{
    int i=0,j=0,k=0;
    poly *p3;
    p3=(poly*)malloc(sizeof(poly)*(p1->n+p2->n));
    while(i<p1->n&&j<p2->n)
    {
        if(p1->e[i].expo>p2->e[j].expo)
        p3->e[k++]=p1->e[i++];
        else if(p1->e[i].expo<p2->e[j].expo)
        p3->e[k++]=p2->e[j++];
        else
        {
           p3->e[k].expo=p1->e[i].expo;
           p3->e[k++].coeff=p1->e[i++].coeff+p2->e[j++].coeff;
        }
    }
    for(;i<p1->n;i++)
    p3->e[k++]=p1->e[i++];
    for(;j<p2->n;j++)
    p3->e[k++]=p2->e[j++];
    p3->n=k;
    return p3;
    
}
void main()
{
    poly p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3=add(&p1,&p2);
    printf("\n");
    display(p1);
    display(p2);
    display(*p3);

}