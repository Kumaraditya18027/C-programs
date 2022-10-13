#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    int size;
    int top;
    char *ex;
}stack;

void push(stack *s,char x)
{
    if(s->top==s->size-1)
    printf("stack overflow\n");
    else
    {
        s->top++;
        s->ex[s->top]=x;
        
    }
}
void pop(stack *s)
{
    char x;
    if(s->top==-1)
    printf("stack underflow\n");
    else
    {
        x=s->ex[s->top];
        s->top--;
    }
}
int isEmpty(stack s)
{
    if(s.top==-1)
    return 1;
    else 
    return 0;
}
int paranthesis(char *c)
{
    stack s;
    s.size=strlen(c);
    s.ex=(char *)malloc(sizeof(char)*(s.size+1));
    s.top=-1;
    
    int i;
    for(i=0;c[i]!='\0';i++)
    {
        if(c[i]=='(')
        push(&s,c[i]);
        else if(c[i]==')')
        {
            if(isEmpty(s))
            return 0;
            else 
            pop(&s);
        }
    }
    return isEmpty(s)?1:0;
}
void main()
{
    stack s;
    char c[20];
    printf("Enter the expression\n");
    scanf("%s",c);
    printf("%d",paranthesis(c));
}

 