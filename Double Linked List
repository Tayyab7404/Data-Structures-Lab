// Double Linked List:

#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode
{
    int val;
    struct DLLNode *pre,*next;
}DLL;

DLL * CreateNode(int v);
DLL * CreateList(int n);
void PrintList(DLL * head);
int ListSize(DLL *head);
DLL * InsertAtStart(DLL *head, DLL * node);
DLL * InsertAtEnd(DLL *head, DLL *node);
DLL * InsertAtPosition(DLL *head, DLL *node, int pos);
DLL * InsertInSorted(DLL *head, DLL * node);
DLL * DeleteAtStart(DLL *head);
DLL * DeleteAtEnd(DLL *head);
DLL * DeleteAtPosition(DLL * head, DLL *node, int pos);
DLL * ReverseList(DLL *head);

void main()
{
    int n,x,pos;
    DLL *head,*newN;

    printf("Enter the size of the list: ");
    scanf("%d",&n);

    head = CreateList(n);
    PrintList(head);
    
    printf("Size of the List = %d\n",ListSize(head));
    
    printf("Enter an element to insert at the start: ");
    scanf("%d",&x);
    newN = CreateNode(x);
    head = InsertAtStart(head,newN);
    PrintList(head);
    
    printf("Enter an element to insert at the End: ");
    scanf("%d",&x);
    newN = CreateNode(x);
    head = InsertAtEnd(head,newN);
    PrintList(head);
    
    printf("Enter the element and position to insert: ");
    scanf("%d %d",&x,&pos);
    newN = CreateNode(x);
    head = InsertAtPosition(head,newN,pos);
    PrintList(head);
    
    printf("Enter an element to insert in the sorted list: ");
    scanf("%d",&x);
    newN = CreateNode(x);
    head = InsertInSorted(head,newN);
    PrintList(head);
    
    printf("The list after deleting the first element:\n");
    head = DeleteAtStart(head);
    PrintList(head);
    
    printf("The list after deleting the last element:\n");
    head = DeleteAtEnd(head);
    PrintList(head);
    
    printf("The list after reversing:\n");
    head = ReverseList(head);
    PrintList(head);
}

DLL * CreateNode(int v)
{
    DLL *node;

    node = (DLL *) malloc(sizeof(DLL));

    node->val = v;
    node->pre = NULL;
    node->next = NULL;

    return node;
}

DLL * CreateList(int n)
{
    int i,v;
    DLL *head=NULL,*tail,*newN;
    
    printf("Enter elements into the list: ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&v);

        newN = CreateNode(v);

        if(head==NULL) head = newN;
        else
        {
            tail->next = newN;
            newN->pre = tail;
        }

        tail = newN;
    }

    return head;
}

void PrintList(DLL * head)
{
    printf("NULL <- ");
    
    while(head!=NULL)
    {
        printf("%d <=> ",head->val);
        head = head->next;
    }

    printf("NULL\n");
}

int ListSize(DLL *head)
{
    int size=0;
    
    while(head!=NULL)
    {
        size++;
        head = head->next;
    }
    
    return size;
}

DLL * InsertAtStart(DLL *head, DLL * node)
{
    if(head==NULL) return node;
    
    head->pre = node;
    node->next = head;
    
    return node;
}

DLL * InsertAtEnd(DLL *head, DLL *node)
{
    if(head==NULL) return node;
    
    DLL *tail = head;
    
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    
    tail->next =node;
    node->pre = tail;
    
    return head;
}

DLL * InsertAtPosition(DLL *head, DLL *node, int pos)
{
    if(head==NULL) return node;
    
    if(pos<=1) return InsertAtStart(head,node);

    if(pos>ListSize(head)) return InsertAtEnd(head,node);
    
    DLL *temp=head;
    
    for(int i=1;i<pos-1;i++)
    {
        temp = temp->next;
    }
    
    node->next = temp->next;
    temp->next->pre = node;
    
    temp->next = node;
    node->pre = temp;
    
    return head;
}

DLL * InsertInSorted(DLL *head, DLL * node)
{
    if(head==NULL) return node;
    
    DLL *temp = head;
    int pos=0;
    
    while(temp != NULL && temp->val < node->val)
    {
        pos++;
        temp = temp->next;
    }
    
    return InsertAtPosition(head, node, pos+1);
}

DLL * DeleteAtStart(DLL *head){
    if(head==NULL) return head;
    
    DLL *temp = head;
    
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    
    head = head->next;
    head->pre = NULL;

    return head;
}

DLL * DeleteAtEnd(DLL *head)
{
    if(head == NULL) return head;
    
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    
    DLL *tail = head;
    
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    
    tail->pre->next = NULL;
    free(tail);
    
    return head;
}

DLL * DeleteAtPosition(DLL * head, DLL *node, int pos)
{
    if(head == NULL) return head;
    
    if(pos==1) return DeleteAtStart(head);
    
    int len = ListSize(head);
    if(pos==len) return DeleteAtEnd(head);
    
    if(pos<1 || pos>len)
    {
        printf("Invalid Position\n");
        return head;
    }
    
    DLL *p=head;
}

DLL * ReverseList(DLL *head)
{
    if(head==NULL || head->next == NULL) return head;
    
    DLL *h=head,*t=head;
    int n = ListSize(head),i,temp;
    
    while(t->next != NULL) t = t->next;
    
    for(i=0;i<n/2;i++){
        temp = h->val;
        h->val = t->val;
        t->val = temp;
        
        h = h->next;
        t = t->pre;
    }
    
    return head;
}
