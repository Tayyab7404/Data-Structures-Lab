// Single Linked List:

#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode
{
    int val;
    struct SLLNode *next;
}SLL;

void PrintList(SLL *head);
int ListSize(SLL *head);
SLL * CreateNode(int val);
SLL * CreateList(int n);
SLL * CreateSortedList(int n);
SLL * InsertAtStart(SLL *head, SLL *node);
SLL * InsertAtEnd(SLL *head, SLL *node);
SLL * InsertAtPosition(SLL *head, SLL *node, int pos);
SLL * InsertInSorted(SLL *head, SLL *node);
SLL * DeletePosition(SLL *head, int pos);
SLL * DeleteElement(SLL *head, int ele);
SLL * SortList1(SLL *head);
SLL * SortList2(SLL *head);
int Find(SLL *head, int ele);
int FindMiddleElement(SLL *head);
SLL * DeleteFromEnd(SLL *head, int pos);
SLL * MergeSortedLists(SLL *h1, SLL *h2);
SLL * DeleteDuplicatesInSorted(SLL* head);
SLL * DeleteDuplicates(SLL *head);
SLL * ReverseList(SLL *head);
SLL * PreviousNode(SLL *head,SLL *tail);

void main()
{
    SLL *head,*newN,*head2;
    int n,x,pos;
    
    printf("Enter size of the list: ");
    scanf("%d",&n);
    head = CreateList(n);
    PrintList(head);
    
    printf("Enter an element to insert at the start: ");
    scanf("%d",&x);
    newN = CreateNode(x);
    head = InsertAtStart(head,newN);
    PrintList(head);
    
    printf("Enter an element to insert at the end: ");
    scanf("%d",&x);
    newN = CreateNode(x);
    head = InsertAtEnd(head,newN);
    PrintList(head);
    
    printf("Enter the element and position to insert: ");
    scanf("%d %d",&x,&pos);
    newN = CreateNode(x);
    head = InsertAtPosition(head,newN,pos);
    PrintList(head);
    
    printf("Enter position of an element to delete: ");
    scanf("%d",&pos);
    head = DeletePosition(head,pos);
    PrintList(head);
    
    printf("Enter an element to delete: ");
    scanf("%d",&x);
    head = DeleteElement(head,x);
    PrintList(head);
    
    head = SortList1(head);
    printf("The sorted list is: \n");
    PrintList(head);
    
    printf("Enter an element to insert in a sorted list: ");
    scanf("%d",&x);
    newN = CreateNode(x);
    head = InsertInSorted(head,newN);
    PrintList(head);
    
    printf("Enter an element to search the list: ");
    scanf("%d",&x);
    Find(head,x);
    
    printf("Enter the size to create a sorted list: ");
    scanf("%d",&n);
    head2 = CreateSortedList(n);
    printf("The sorted list is:\n");
    PrintList(head2);
    
    printf("The middle element in the list is: %d",FindMiddleElement(head));
    
    printf("Enter position of the element from the end to delete: ");
    scanf("%d",&pos);
    head = DeleteFromEnd(head,pos);
    PrintList(head);
    
    head = ReverseList(head);
    printf("The Reversed List is:\n");
    PrintList(head);
    
}

void PrintList(SLL *head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int ListSize(SLL *head)
{
    int size = 0;
    
    while(head!=NULL)
    {
        size++;
        head = head->next;
    }
    
    return size;
}

SLL * CreateNode(int val)
{
    SLL * head;
    
    head = (SLL*)malloc(sizeof(SLL));
    
    head->val = val;
    head->next = NULL;
    
    return head;
}

SLL * CreateList(int n)
{
    SLL *head=NULL, *newN, *tail; 
    int i,v;
    
    printf("Enter elements into the list: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&v);
        
        newN = CreateNode(v);
        
        if(head==NULL) head = newN;
        else tail->next = newN;
        
        tail = newN;
    }
    
    return head;
}

SLL * CreateSortedList(int n)
{
    SLL *head=NULL,*newN;
    int val;
    
    printf("Enter elements into the list: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        
        newN = CreateNode(val);
        
        head = InsertInSorted(head,newN);
    }
    
    return head;
}

SLL * InsertAtStart(SLL *head, SLL *node)
{
    if(head==NULL) return node;
    
    node->next = head;
    
    return node;
}

SLL * InsertAtEnd(SLL *head, SLL *node)
{
    if(head == NULL) return node;
    
    SLL *temp = head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    
    return head;
}

SLL * InsertAtPosition(SLL *head, SLL *node, int pos)
{
    if(head == NULL) return node;
    
    if(pos<2) return InsertAtStart(head,node);
    
    int len = ListSize(head);
    if(pos>len) return InsertAtEnd(head,node);
    
    SLL *temp = head;
    
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    
    node->next = temp->next;
    temp->next = node;
    
    return head;
}

SLL * InsertInSorted(SLL *head, SLL *node)
{
    if(head==NULL) return node;
    
    SLL *temp = head;
    int pos = 0;
    
    while(temp!=NULL && temp->val < node->val)
    {
        pos++;
        temp = temp->next;
    }
    head = InsertAtPosition(head,node,pos+1);
    
    return head;
}

SLL * DeletePosition(SLL *head, int pos)
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return head;
    }
    
    int len = ListSize(head);
    
    if(pos<1 || pos>len)
    {
        printf("Invalid position!\n");
        return head;
    }
    
    SLL *p=head,*c;
    
    if(pos == 1)
    {
        head = head->next;
        free(p);
        return head;
    }

    for(int i=1;i<pos-1;i++)
    {
        p = p->next;
    }

    c = p->next;
    p->next = c->next;
    free(c);

    return head;
}

SLL * DeleteElement(SLL *head, int ele)
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return head;
    }
    
    SLL *p=head,*c;
    
    if(head->val == ele)
    {
        head = head->next;
        free(p);
        return head;
    }
    
    
    while(p->next != NULL)
    {
        if(p->next->val == ele)
        {
            c = p->next;
            p->next = c->next;
            free(c);
            return head;
        }
        
        p = p->next;
    }

    printf("Element %d is not found in the list!\n",ele);

    return head;
}

SLL * SortList1(SLL *head)
{
    if(head==NULL) return NULL;
    
    int len = ListSize(head),temp;
    SLL *t;
    
    for(int i=0;i<len-1;i++)
    {
        t = head;
        
        for(int j=0; j<len-i-1; j++)
        {
            if(t->val > t->next->val)
            {
                temp = t->val;
                t->val = t->next->val;
                t->next->val = temp;
            }
            
            t = t->next;
        }
    }
    
    return head;
}

SLL * SortList2(SLL *head)
{
    if(head==NULL) return NULL;
    
    SLL *p=head,*c,*least;
    
    while(p->next != NULL)
    {
        least = p;
        c = p->next;
        
        while(c!=NULL){
            if(least->val > c->val)
            {
                least = c;
            }
            
            c = c->next;
        }
        
        int temp = p->val;
        p->val = least->val;
        least->val = temp;
        
        p = p->next;
    }
    
    return head;
}

int Find(SLL *head, int ele)
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return 0;
    }
    
    SLL *p = head;
    
    while(p != NULL)
    {
        if(p->val == ele) 
        {
            printf("Element '%d' is found in the list\n",ele);
            
            return 1;
        }
        
        p = p->next;
    }
    
    printf("Element '%d' is not found in the list!\n",ele);
    
    return 0;
}

int FindMiddleElement(SLL *head)
{
    int len = ListSize(head);
    
    for(int i=1;i<=len/2;i++)
    {
        head = head->next;
    }
    
    return head->val;
}

SLL * DeleteFromEnd(SLL *head, int pos)
{
    int len = ListSize(head);
    
    return DeletePosition(head, len-pos+1);
}

SLL * MergeSortedLists(SLL *h1, SLL *h2)
{
    if (!h1)
        return h2;
    else if (!h2)
        return h1;

    SLL *h3 = NULL, *tail, *node;

    while (h1 || h2)
    {
        if (!h1 && h2)
        {
            node = h2;
            h2 = h2 -> next;
        }
        else if (h1 && !h2)
        {
            node = h1;
            h1 = h1 -> next;
        }
        else if (h1 -> val < h2 -> val)
        {
            node = CreateNode(h1 -> val);
            h1 = h1 -> next;
        }
        else
        {
            node = CreateNode(h2 -> val);
            h2 = h2 -> next;
        }

        if (!h3)
        {
            h3 = node;
        }
        else
        {
            tail -> next = node;
        }
        tail = node;
    }
    return h3;
}

SLL* DeleteDuplicatesInSorted(SLL* head)
{
    if (!head)
    {
        printf("List is empty!\n");
        return head;
    }
    
    SLL *p = head, *c;
    
    while (p -> next)
    {
        if (p -> val == p->next->val)
        {
            c = p -> next;
            p -> next = c -> next;
            free(c);
        }
        else
            p = p -> next;
    }
    return head;
}

SLL* DeleteDuplicates(SLL *head)
{
    if (!head)
    {
        printf("List is empty!\n");
        return head;
    }

    SLL *p = head, *c, *t;

    while (p -> next)
    {
        c = p;
        while (c -> next)
        {
            if (p -> val == c -> next -> val)
            {
                t = c -> next;
                c -> next = t -> next;
                free(t);
            }
            else
                c = c -> next;
        }
        p = p -> next;
    }
    return head;
}

SLL * PreviousNode(SLL *head,SLL *tail)
{
    if(head==NULL) return head;
    
    while(head->next != tail)
    {
        head = head->next;
    }
    
    return head;
}

SLL * ReverseList(SLL *head)
{
    if(head==NULL) return head;
    
    SLL *p=head,*tail=head;
    int n = ListSize(head),i,temp;
    
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    
    for(i=0;i<n/2;i++)
    {
        temp = p->val;
        p->val = tail->val;
        tail->val = temp;
        
        p = p->next;
        tail = PreviousNode(head,tail);
    }
    
    return head;
}
