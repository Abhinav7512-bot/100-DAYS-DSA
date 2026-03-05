#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i=0, k=0;
    
    scanf("%s", infix);

    while(infix[i])
    {
        if(isalnum(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while(top!=-1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while(top!=-1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}