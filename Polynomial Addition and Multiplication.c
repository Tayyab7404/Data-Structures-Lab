#include<stdio.h>
#include<stdlib.h>

typedef struct SLLPolynomial
{
    int coeff,expo;
    struct SLLPolynomial *next;
}SLLP;

SLLP * CreateNode(int c,int e);
SLLP * CreatePoly(int n);
void PrintPoly(SLLP *head);
SLLP * AddPoly(SLLP *h1, SLLP *h2);
SLLP * MultiplyPoly(SLLP *h1, SLLP *h2);
SLLP * SortPoly(SLLP *head);
void Swap(SLLP *x, SLLP *y);
SLLP * SimplifyPoly(SLLP *head);

void main()
{
    int n1,n2;
    SLLP *head1=NULL,*head2=NULL,*head3=NULL;

    printf("Enter size of 1st Polynomial: ");
    scanf("%d",&n1);

    if(n1>0)    head1 = CreatePoly(n1);

    printf("Enter size of 2nd Polynomial: ");
    scanf("%d",&n2);

    if(n2>0)    head2 = CreatePoly(n2);

    printf("Polynomial 1: ");
    PrintPoly(head1);

    printf("Polynomial 2: ");
    PrintPoly(head2);

    head3 = AddPoly(head1,head2);
    printf("Polynomial 1 + Polynomial 2: ");
    PrintPoly(head3);

    head3 = MultiplyPoly(head1,head2);
    printf("Polynomial 1 * Polynomial 2: ");
    PrintPoly(head3);
}

SLLP * CreateNode(int c,int e)
{
    SLLP *newN;
    
    newN = (SLLP*) malloc(sizeof(SLLP));
    
    newN->coeff = c;
    newN->expo = e;
    newN->next = NULL;
    
    return newN;
}

SLLP * CreatePoly(int n)
{
    SLLP *head=NULL,*tail,*newN;
    int i,c,e;
    
    printf("Enter the Polynomial: ");
    
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&c,&e);
        
        newN = CreateNode(c,e);
        
        if(head==NULL) head = newN;
        else tail->next = newN;
        
        tail = newN;
    }
    
    return head;
}

void PrintPoly(SLLP *head)
{
    head = SortPoly(head);
    head = SimplifyPoly(head);
    
    if(head!=NULL)
    {
        while(head)
        {
            printf("%dx^%d ",head->coeff,head->expo);
            if(head->next != NULL) printf("+ ");
            head = head->next;
        }
        printf("= 0\n");
    }
    
    else printf("0\n");
}

SLLP * AddPoly(SLLP *h1, SLLP *h2)
{
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    
    SLLP *h3=NULL,*newN,*tail;
    
    while(h1!=NULL || h2!=NULL)
    {
        if (h1 && !h2)
        {
            newN = CreateNode(h1 -> coeff, h1 -> expo);
            h1 = h1 -> next;
        }
        else if (!h1 && h2)
        {
            newN = CreateNode(h2 -> coeff, h2 -> expo);
            h2 = h2 -> next;
        }
        
        else if(h1->expo == h2->expo)
        {
            newN = CreateNode(h1->coeff + h2->coeff, h1->expo);
            
            h1 = h1->next;
            h2 = h2->next;
        }
        
        else if(h1->expo < h2->expo)
        {
            newN = CreateNode(h2->coeff,h2->expo);
            
            h2 = h2->next;
        }
        
        else
        {
            newN = CreateNode(h1->coeff,h1->expo);
            
            h1 = h1->next;
        }
        
        if(h3 == NULL) h3 = newN;
        else tail->next = newN;
        
        tail = newN;
    }
    
    h3 = SortPoly(h3);
    h3 = SimplifyPoly(h3);
    
    return h3;
}

SLLP * MultiplyPoly(SLLP *h1, SLLP *h2)
{
    SLLP *head = NULL, *tail = NULL, *ans = NULL, *newN, *temp=h2;
    
    while (h1 != NULL)
    {
        while (temp != NULL)
        {
            newN = CreateNode(h1 -> coeff * temp -> coeff, h1 -> expo + temp -> expo);
            
            if (head == NULL)   head = newN;
            else    tail -> next = newN;
            tail = newN;
            
            temp = temp -> next;
        }
        
        ans = AddPoly(ans, head);
        
        h1 = h1 -> next;
    }
    
    ans = SortPoly(ans);
    ans = SimplifyPoly(ans);
    
    return ans;
}

SLLP * SortPoly(SLLP *head)
{
    if (head == NULL)   return head;

    SLLP *p = head, *c, *big;
    
    while (p -> next != NULL)
    {
        big = p;
        c = p -> next;
        
        while (c != NULL)
        {
            if (c -> expo > big -> expo)  big = c;
            c = c -> next;
        }
        
        Swap(p, big);
        
        p = p -> next;
    }
    
    return head;
}

void Swap(SLLP *x, SLLP *y)
{
    int c = x -> coeff;
    int e = x -> expo;
    
    x -> coeff = y -> coeff;
    x -> expo = y -> expo;
    
    y -> coeff = c;
    y -> expo = e;
}

SLLP* SimplifyPoly(SLLP *head)
{
    if (head == NULL)  return head;

    SLLP *p = head, *c;

    while (p -> next != NULL)
    {
        if (p -> expo == p -> next -> expo)
        {
            c = p -> next;
            p -> coeff = p -> coeff + c -> coeff;
            p -> next = c -> next;
            free(c);
        }
        
        p = p -> next;
    }
    
    return head;
}
