// Breadth First Search:

#include<stdio.h>
#include<stdlib.h>
// #define n 5

//int adj[n][n]={{0,1,0,0,1}, {1,0,1,0,0}, {0,1,0,1,0}, {0,0,1,0,1}, {1,0,0,1,0}}; --> Pentagon
//int adj[n][n]={{0,1,1,1,1}, {1,0,1,1,1}, {1,1,0,1,1}, {1,1,1,0,1}, {1,1,1,1,0}}; --> Star in Pentagon
//int adj[n][n]={{0,0,1,1,0}, {0,0,0,1,1}, {1,0,0,0,1}, {1,1,0,0,0}, {0,1,1,0,0}}; --> Star

int adj[20][20], n, Queue[10], front=-1, rear=-1, visited[10]={0};

void Enqueue(int val);
int Dequeue();
void bfs(int v);

void main()
{
    printf("Enter the no.of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the edges of each node: \n");
    for (int i=0; i<n; i++) 
    {
        printf("Node %d: ", i);
        for (int j=0; j<n; j++) 
        {
          scanf("%d", &adj[i][j]);
        }
    }
    
    int x;
    
    printf("Enter the starting node: ");
    scanf("%d",&x);
    
    bfs(x);
    printf("\n");
}

void Enqueue(int val)
{
    Queue[++rear] = val;
    
    if(front == -1) front++;
}

int Dequeue()
{
    if(front == -1 || front > rear) return -1; 
    
    return  Queue[front++];
}

void bfs(int v)
{
    if(visited[v] == 0)   
        printf("%d ",v);

    visited[v] = 1;

    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && visited[i]==0)
            Enqueue(i);
    }

    int t = Dequeue();
    if(t>=0) bfs(t);
}
