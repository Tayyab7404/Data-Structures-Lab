// Stacks:

#include<stdio.h>
#include<stdlib.h>

int stack[10],top=-1;

int push(int val)
{
    if(top>8)
    {
        printf("Stack Overflow!\n");
        return -99;
    }
    
    stack[++top] = val;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty!\n");
        return -99;
    }
    
    return stack[top--];
}

int peek()
{
    if(top==-1)
    {
        printf("Stack is empty!\n");
        return -99;
    }
    
    return stack[top];
}

void printstack()
{
    if(top==-1)
    {
        printf("Stack is empty!\n");
        return;
    }
    
    int temp = top;
    
    printf("Elements in the stack:\n");
    while(temp>=0)
    {
        printf("%d -> ",stack[temp]);
        temp--;
    }
    printf("END\n");
}

void main()
{
    int x,ch;
    
    printf("\nMENU\n----\n1.Push\n2.Pop\n3.Peek\n4.Print\n5.Exit\n");
    
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&x);
                
                x = push(x);
                
                if(x!=-99)
                    printf("%d is pushed into the stack\n",x);
                    
                break;
                
            case 2:
                x = pop();
                
                if(x!=-99)
                    printf("%d is poped out of the stack\n",x);
                    
                break;
                
            case 3:
                x = peek();
                
                if(x!=-99)
                    printf("%d is on top of the stack\n",x);
                    
                break;
                
            case 4:
                printstack();
                
                break;
                
            case 5:
                printf("Program terminated\n");
                
                exit(0);
                
            default:
                printf("Invalid input!\n");
        }
    }
}
