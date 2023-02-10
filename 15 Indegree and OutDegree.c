// Indegree and Outdegree:

#include<stdio.h>

int n, G[10][10], a[10];

void readgraph();
void in_outdegree();

void main()
{
    readgraph();
    
    in_outdegree();
}

void readgraph()
{
    int i, j;
    
    printf("Enter the number of vertices of graph: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix of graph:\n");
    
    printf("  ");
    for(i=0; i<n; i++) printf("%c ", i+97);
    printf("\n");
    
    for(i=0; i<n; i++)
    {
        printf("%c ", i+97);
        
        for(j=0; j<n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
}

void in_outdegree()
{
    int i, j, s1, s2;
    
    for(i=0; i<n; i++)
    {
        s1 = s2 = 0;
        
        for(j=0; j<n; j++)
        {
            s1 = s1 + G[i][j];
            s2 = s2 + G[j][i];
        }
        
        printf("\n");
        printf("The Indegree(%c) : %d\n", i+97, s2);
        printf("The Outdegree(%c) : %d\n", i+97, s1);
        printf("\n");
    }
}
