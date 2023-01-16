// Stacks Using Linked Lists:

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *top = NULL;

Node* createNode(int v);
void push(int v);
int pop();
int peek();
void PrintStack();

int main()
{
    int x,ch;
    
    printf("\nMENU\n----\n1.Push\n2.Pop\n3.Peek\n4.Print\n5.Exit\n");
    
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&x);
            
                push(x);
            
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
                PrintStack();
            
                break;
            
            case 5:
                printf("Program terminated\n");
            
                exit(0);
            
            default:
                printf("Invalid input!\n");
        }
    }
}

Node* createNode(int v)
{
    Node *n = (Node*)malloc(sizeof(Node));
    
    n -> val = v;
    n -> next = NULL;
    
    return n;
}

void push(int v)
{
    Node *newNode = createNode(v);
    newNode -> next = top;
    top = newNode;
}

int pop()
{
    if (top==NULL)
    {
        printf("Stack is empty!\n");
        return -99;
    }
    
    int v = top -> val;
    
    Node *t = top;
    top = top -> next;
    free(t);
    
    return v;
}

int peek()
{
    if (top==NULL)
    {
        printf("Stack is empty!\n");
        return -99;
    }
    
    return top -> val;
}

void PrintStack()
{
    if(top==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    
    Node *temp = top;
    
    printf("Elements in the stack:\n");
    while (temp)
    {
        printf("%d ->", temp -> val);
        temp = temp -> next;
    }
    printf("END\n");
}
