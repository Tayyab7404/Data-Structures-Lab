// Circular Queue:

#include<stdio.h>
#include<stdlib.h>

int CQue[10],front=-1,rear=-1;

int Enqueue(int val)
{
    if((rear+1)%10 == front)
    {
        printf("Queue is Full!\n");
        return -99;
    }
    
    rear = (rear+1)%10;
    
    CQue[rear] = val;
    
    if(front == -1)
    {
        front++;
    }
    
    return CQue[rear];
}

int Dequeue()
{
    if(rear == -1 || front == -1)
    {
        printf("Queue is Empty!\n");
        return -99;
    }
    
    int temp = CQue[front];
    
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    
    else
    {
        front = (front+1)%10;
    }
    
    return temp;
}

int PeekQueue()
{
    if(rear == -1 || front == -1)
    {
        printf("Queue is Empty!\n");
        return -99;
    }
    
    return CQue[front];
}

void PrintQueue()
{
    if(rear == -1 || front == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    
    printf("ELements in the Queue:\n");
    
    int i;
    
    for(i=front; i!=rear; i=(i+1)%10)
    {
        printf("%d ",CQue[i]);
    }
    printf("%d\n",CQue[i]);
}

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
                
                x = Enqueue(x);
                
                if(x!=-99)
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
