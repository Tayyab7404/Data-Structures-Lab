// Binary Search Tree:

#include<stdio.h>
#include<stdlib.h>

typedef struct BinTreeNode
{
    int data;
    struct BinTreeNode *left, *right;
}BinTreeNode;

BinTreeNode * CreateNode(int val);
BinTreeNode * InsertNode(BinTreeNode *root, int val);
BinTreeNode * Find(BinTreeNode *root, int key);
BinTreeNode * FindMin(BinTreeNode *root);
BinTreeNode * FindMax(BinTreeNode *root);
BinTreeNode * DeleteNode(BinTreeNode *root, int key);
void InOrder(BinTreeNode *root);
void PreOrder(BinTreeNode *root);
void PostOrder(BinTreeNode *root);
BinTreeNode * InOrderPredecessor(BinTreeNode *root);
BinTreeNode * InOrderSuccessor(BinTreeNode *root);

void main()
{
    int n,x;
    BinTreeNode *root=NULL;
    
    printf("Enter no of elements in the Binary Search Tree: ");
    scanf("%d",&n);
    
    printf("Enter the elements into the Binary Search Tree: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        root = InsertNode(root, x);
    }
    
    printf("Root of the Tree: %d\n",root->data);
    
    printf("Enter an element to delete from the Tree: ");
    scanf("%d",&x);
    root = DeleteNode(root, x);
    
    printf("InOrder traversal of the Tree: ");
    InOrder(root);
    printf("\n");
    printf("PreOrder traversal of the Tree: ");
    PreOrder(root);
    printf("\n");
    printf("PostOrder traversal of the Tree: ");
    PostOrder(root);
    printf("\n");
    
    BinTreeNode *t1 = InOrderPredecessor(root);
    BinTreeNode *t2 = InOrderSuccessor(root);
    printf("Inorder predecessor of %d is: %d\n", root->data, t1->data);
    printf("Inorder successor of %d is: %d\n", root -> data, t2 -> data);
}

BinTreeNode * CreateNode(int val)
{
    BinTreeNode *node = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

BinTreeNode * InsertNode(BinTreeNode *root, int val)
{
    if(root == NULL) return CreateNode(val);
    
    if(val < root->data)
        root->left = InsertNode(root->left, val);
    else if(val > root->data) 
        root->right = InsertNode(root->right, val);

    return root;
}

BinTreeNode * Find(BinTreeNode *root, int key)
{
    BinTreeNode *temp = root;
    
    while(temp != NULL)
    {
        if(temp->data == key) return temp;
        
        else if(temp->data > key) temp = temp->left;
        
        else temp = temp->right;
    }
    
    return NULL;
}

BinTreeNode * FindMin(BinTreeNode *root)
{
    BinTreeNode *temp = root;
    
    if(root == NULL) return root;
    
    while(temp->left != NULL) temp = temp->left;
    
    return temp;
}

BinTreeNode * FindMax(BinTreeNode *root)
{
    BinTreeNode *temp = root;
    
    if(root == NULL) return root;
    
    while(temp->right != NULL) temp = temp->right;
    
    return temp;
}

BinTreeNode * DeleteNode(BinTreeNode *root, int key)
{
    BinTreeNode * temp = root;
    
    if(root == NULL) return root;
    
    if(key < root->data)
        root->left = DeleteNode(root->left, key);
    
    else if(key > root->data)
        root->right = DeleteNode(root->right, key);
        
    else
    {
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        
        else
        {
            temp = FindMin(root->right);
            root->data = temp->data;
            root->right = DeleteNode(root->right, key);
        }
    }
    
    return root;
}

void InOrder(BinTreeNode *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

void PreOrder(BinTreeNode *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(BinTreeNode *root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}

BinTreeNode* InOrderPredecessor(BinTreeNode *root)
{
  return FindMax(root->left);
}
BinTreeNode* InOrderSuccessor(BinTreeNode *root)
{
  return FindMin(root -> right);
}
