// Dynamically Linked Queue:

#include<stdio.h>
#include<stdlib.h>

typedef struct QLL
{
    int val;
    struct QLL *next;
}QLL;

QLL *front=NULL, *rear=NULL;

QLL * CreateNode(int val);
void Enqueue(int val);
int Dequeue();
int PeekQueue();
void PrintQueue();

void main()
{
    int x,ch;
    
    printf("\nMENU\n----\n1.Enqueue\n2.Dequeue\n3.PeekQueue\n4.PrintQueue\n5.Exit\n");
    
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("Enter the element to Enqueue: ");
                scanf("%d",&x);
                
                Enqueue(x);
    
                printf("%d is Enqueued into the Queue\n",x);
                    
                break;
                
            case 2:
                x = Dequeue();
                
                if(x!=-99)
                    printf("%d is Dequeued from the Queue\n",x);
                    
                break;
                
            case 3:
                x = PeekQueue();
                
                if(x!=-99)
                    printf("%d is on front of the Queue\n",x);
                    
                break;
                
            case 4:
                PrintQueue();
                
                break;
                
            case 5:
                printf("Program terminated\n");
                
                exit(0);
                
            default:
                printf("Invalid input!\n");
        }
    }
}

QLL * CreateNode(int val)
{
    QLL *newN = (QLL *) malloc(sizeof(QLL));
    
    newN->val = val;
    newN->next = NULL;
    
    return newN;
}

void Enqueue(int val)
{
    QLL *newN;
    
    newN = CreateNode(val);
    
    if(front == NULL)   front = newN;
    else rear->next = newN;
    
    rear = newN;
}

int Dequeue()
{
    if(front==NULL) 
    {
        printf("Queue is empty!\n");
        return -99;
    }
    
    QLL *temp = front;
    front = front->next;
    int a = temp->val;
    
    free(temp);
    
    return a;
}

int PeekQueue()
{
    if(front==NULL) 
    {
        printf("Queue is empty!\n");
        return -99;
    }
    
    return front->val;
}

void PrintQueue()
{
    if(front==NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    
    QLL *temp = front;
    
    while(temp != NULL)
    {
        printf("%d -> ",temp->val);
        temp = temp->next;
    }
    printf("END\n");
}
