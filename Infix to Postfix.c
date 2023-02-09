// Infix to Postfix:

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[50];
int top = -1;

void push(char c);
char pop();
char peek();
char * Postfix(char infix[]);

void main()
{
    char infix[50];
    
    printf("Enter an Infix expression: ");
    scanf(" %[^\n]", infix);
    
    char *postfix = Postfix(infix);
    printf("%s in Postfix: %s\n", infix, postfix);
}

void push(char c)
{
    if (top == 49)
    {
        printf("Stack is full\n");
        return;
    }
    
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        return 1;
    }
    
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return 1;
    }
    
    return stack[top];
}

char * Postfix(char infix[])
{
    char a[100] = {0};
    a[1] = 0;
    a['^'] = 4;
    a['%'] = 3;
    a['/'] = 3;
    a['*'] = 3;
    a['+'] = 2;
    a['-'] = 2;
    a['('] = 1;
    a[')'] = 1;
    
    int index = -1;
    
    char *postfix = (char *) malloc(strlen(infix) * sizeof(char));
    
    for(int i=0;infix[i]!='\0';i++)
    {
        if(infix[i]>=97 && infix[i]<=122)
        {
            postfix[++index] = infix[i];
        }
        
        else
        {
            if(infix[i]==')')
            {
                while(peek()!='(')
                {
                    postfix[++index] = pop();
                }
                
                pop();
            }
            
            else
            {
                while (infix[i] != '(' && a[infix[i]] <= a[peek()])
                {
                    postfix[++index] = pop();
                }
                
                push(infix[i]);
            }
        }
    }

    if(top!=-1)
    {
        while (top >= 0)
        {
            postfix[++index] = pop();
        }
    }

    return postfix;
}
