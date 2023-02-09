// Evaluate Postfix Expression:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[30], top = -1;

void push(int v);
int pop();
int peek();
int EvalPostfix(char postfix[30]);

void main()
{
    char postfix[30];
    
    printf("Enter a Postfix Expression: ");
    scanf(" %[^\n]", postfix);
    
    printf("Value of %s = %d\n", postfix, EvalPostfix(postfix));
}

void push(int v)
{
    if (top == 28)
    {
        printf("Stack Overflow!\n");
        return;
    }
    
    stack[++top] = v;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    
    return stack[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    
    return stack[top];
}

int EvalPostfix(char postfix[30])
{
    char c;
    int i,n1,n2,d;
    
    for(i=0;i<strlen(postfix);i++)
    {
        c = postfix[i];
        
        switch(c)
        {
            case '+':
                n1 = pop();
                n2 = pop();
                push(n2+n1);
                break;
            case '-':
                n1 = pop();
                n2 = pop();
                push(n2-n1);
                break;
            case '*':
                n1 = pop();
                n2 = pop();
                push(n2*n1);
                break;
            case '/':
                n1 = pop();
                n2 = pop();
                push(n2/n1);
                break;
            case '%':
                n1 = pop();
                n2 = pop();
                push(n2%n1);
                break;
            default:
                d = c - '0';
                push(d);
        }
    }
    
    if (top > 0)
	{
		printf("Invalid expression!!\n");
		return 0;
	}
	
	return peek();
}
