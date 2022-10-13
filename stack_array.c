#include<stdio.h>
#include<stdlib.h>
 typedef struct stack
{
    int n;
    int top;
    int *s;
}stack;
void push(stack *st,int x)
{
    if(st->top==st->n-1)
    printf("stack overflow\n");
    else 
    {
        st->top++;
        st->s[st->top]=x;
    }
}
void display(stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d ",st.s[i]);
    }
}

void create(stack *st)
{
    
    printf("Enter the size of the stack\n");
    scanf("%d",&st->n);
    st->s=(int *)malloc(sizeof(int)*st->n);
    st->top=-1;
    
}
int pop(stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
    printf("Stack Underflow\n");
    return x;
    }
    else
    {
        x=st->s[st->top];
        st->top--;
        return x;
    }


}
int peek(stack st,int index)//index from above the stack//
{
   int x=-1;
   if(st.top-index+1<0)
   return x;
   else
   {
    x=st.s[st.top-index+1];
    return x;
   }
}
int stacktop(stack st)
{
    if(st.top==-1)
    {
        return -1;
    }
    else 
    return st.s[st.top];
}
int isFull(stack st)
{
    if(st.top==st.n-1)
    return 1;
    else
    return 0;
}
int isEmpty(stack st)
{
    if(st.top==-1)
    return 1;
    else 
    return 0;
}
void main()
{
    stack st;
    create(&st);
    push(&st,1);
    push(&st,2);
    push(&st,4);
    push(&st,6);
    display(st);
    printf("%d \n",pop(&st));
    printf("%d\n",peek(st,3));
    printf("%d",stacktop(st));

}