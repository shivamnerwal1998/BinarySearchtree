69#include<iostream>
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
void preOrderTraversal(bst *tree)
{
    if(tree != NULL)
    {
        printf("%d\t",tree->info) ;
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }

}
void postOrderTraversal(bst *tree)
{
    if(tree != NULL)
    {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d\t",tree->info) ;
    }

}void inOrderTraversal(bst *tree)
{
    if(tree != NULL)
    {
        inOrderTraversal(tree->left);
        printf("%d\t",tree->info) ;
        inOrderTraversal(tree->right);
    }

}
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
