#include<iostream>
using namespace std;
struct bst{
    int info;
    struct bst *left;
    struct bst *right;
};
typedef struct bst bst;

void createEmptyTree(bst **tree)
{
    *tree = NULL;

}
// Using queue for level order traversal   

/*

typedef struct NodeType
{
    int info ;
    struct NodeType *next ;

}node;
typedef struct queueType
{
    node *front ;
    node *rear ;
}queue ;

void createQueue(queue *q)
{
    q->front = NULL ;
    q->rear = NULL ;

}
void enqueue(queue *q,int data)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = data ;
    ptr->next = NULL ;
    if( q->rear == NULL )
    {
        q->front = q->rear = ptr ;
    }
    else
    {
        (q->rear)->next = ptr ;
        q->rear = ptr ;

    }
}

void dequeue(queue *q)
{
    node *ptr ;
    ptr = q->front ;
    if( q->front ==  NULL && q->rear == NULL  )
    {
        printf("\nQUEUE IS EMPTY\n");
        return ;
    }
    (q->front) = (q->front)->next ;
    printf("%d\n",ptr->info) ;
    free(ptr) ;
}
*/

/*Iterative function to insert element in Binary Search Tree */
void insertElement(bst **tree,int element)
{
    bst *ptr , *node , *parent ;
    ptr = (bst*)malloc(sizeof(bst)) ;
    ptr->info = element ;
    ptr->left = ptr->right = NULL ;
    if(*tree == NULL){
        *tree = ptr ;
        return ;
    }
    node = (*tree) ;
    parent = NULL ;
    while(node != NULL)
    {
        parent = node ;
        if(element < parent->info)
            node = node -> left ;
        else
            node = node -> right ;
    }
    if(element < parent -> info)
        parent->left = ptr;
    else
        parent->right = ptr ;
}

/* Recursive function to insert element in binary search tree*/
void insertElementRecursive(bst **tree,int element)
{
     bst *ptr ;
     ptr = (bst*)malloc(sizeof(bst));
     ptr->info = element ;
     ptr->left = ptr->right =NULL ;
     if(*tree == NULL)
     {
        *tree = ptr;
     }
     else{
            if(element < (ptr->info))
                insertElementRecursive(&((*tree)->left),element);
            else
                insertElementRecursive(&((*tree)->right),element);

     }

}
/*
    preorder traversal :
    root
    left
    right
*/
void preOrderTraversal(bst *tree)
{
    if(tree != NULL)
    {
        printf("%d\t",tree->info) ;
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }

}
/*
    post order traversal :
    left
    right
    root
*/
void postOrderTraversal(bst *tree)
{
    if(tree != NULL)
    {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d\t",tree->info) ;
    }

}

/* Inorder traversal :
    left
    root
    right
*/
/* inorder trasversal displays the elements of b.s.t. in sorted form
*/

void inOrderTraversal(bst *tree)
{
    if(tree != NULL)
    {
        inOrderTraversal(tree->left);
        printf("%d\t",tree->info) ;
        inOrderTraversal(tree->right);
    }

}

/* main function */
int main()
{
    bst *root;
    createEmptyTree(&root);
    //insertElement();
    insertElementRecursive(&root,10);
    insertElementRecursive(&root,20);
    insertElementRecursive(&root,5);
    insertElementRecursive(&root,15);
    insertElementRecursive(&root,30);



    cout<<"\nTraversing the tree in pre order\n";
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    return 0;
}
