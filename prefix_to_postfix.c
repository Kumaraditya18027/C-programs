#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
    int n;
	char *s;
	int top;
}stack;
void main()
{
    stack st;
    printf("Enter the size of the expression\n");
    scanf("%d",&st.n);
    st.n=(char *)malloc(sizeof(char)*(st.n+2));
}

