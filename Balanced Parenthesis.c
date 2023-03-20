// Balanced Parenthesis:

#include<stdio.h>

char stack[50];
int top = -1;

void push(char c);
char pop();
char peek();
int isValid(char * expr);

void main()
{
    char expr[50];
    
    printf("Enter the expression: ");
    scanf("%[^\n]",expr);
    
    if(isValid(expr)) printf("Valid Expression\n");
    else printf("Invalid Expression\n");
}

void push(char c)
{
	if (top == 48) return;
		
	stack[++top] = c;
}

char pop()
{
	if (top == -1)  return 1;
	
	return stack[top--];
}

char peek()
{
	if (top == -1)  return 1;
	
	return stack[top];
}

int isValid(char * expr)
{
	for(int i=0;expr[i] != '\0';i++)
	{
	    if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{') push(expr[i]);
	    
	    else
	    {
	        switch(expr[i])
	        {
	            case ')':
	                if(peek() == '(') pop();
	                else return 0;
	                break;
	                
	            case ']':
	                if(peek() == '[') pop();
	                else return 0;
	                break;
	                
	            case '}':
	                if(peek() == '{') pop();
	                else return 0;
	                break;
	        }
	    }
	}
	
	if(top != -1) return 0;
	
	return 1;
}
