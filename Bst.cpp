#include<iostream>
using namespace std ;


/* self-Referential structure of binary search tree  */

typedef struct bst {
    int data ;
    struct bst *left ;
    struct bst *right ;
}bst ;


/* Function to create empty binary search tree  */
void createEmpty(bst **tree)
{
    *tree = NULL ;

}

/* function to insert node in binary search tree  */
void insertNode(bst **tree,int info)
{
    bst *ptr , *node  , *parent;
    ptr = (bst*) malloc(sizeof(bst)) ;
    ptr->data = info ;
    ptr->left = NULL ;
    ptr->right = NULL ;
    if(*tree == NULL ){
        *tree = ptr ;
        return  ;
    }
    else
    {
        parent = NULL;
        node = (*tree) ;
        while(node != NULL )
        {
            parent = node ;
            if(info < node-> data )
                node = node -> left ;
            else
                node = node -> right ;
        }
    }
        if (info < (parent -> data) )
                parent ->left = ptr ;
        else
            parent -> right = ptr ;
}

/* InOrder Traversal of binary search tree */
void inOrderTraversal(bst *tree)
{
    if(tree != NULL )
    {
        inOrderTraversal(tree->left ) ;
        cout << tree->data << "\t" ;
        inOrderTraversal(tree->right) ;
    }

}
/* Pre - Order Traversal  */
void preOrderTraversal(bst *tree)
{
    if(tree != NULL )
    {
        cout << tree->data << "\t" ;
        preOrderTraversal(tree->left) ;
        preOrderTraversal(tree->right) ;
    }

}
/* Post - Order Traversal  */
void postOrderTraversal(bst *tree)
{
    if(tree != NULL )
    {
        preOrderTraversal(tree->right) ;
        preOrderTraversal(tree->left) ;
        cout << tree->data << "\t" ;
    }

}
bst* maxValue(bst* tree)
{
    while( tree != NULL && tree->right != NULL  )
    {
        tree = tree->right ;
    }
    return tree ;

}
/* Function to find smallest element in binary search tree */

bst* minValue(bst*tree)
{
    while(tree != NULL && tree->left != NULL)
        tree = tree->left ;
    return tree ;
}


/*Function to Delete a  Node in Binary Search Tree */
void deleteNode(bst **tree ,  int element )
{
    bst *temp ;
    if(*tree == NULL )
        return ;
    else if(element < (*tree)->data)
        deleteNode( &((*tree)->left) , element ) ;
    else if(element > (*tree)->data)
        deleteNode(&((*tree)->right), element) ;
    else
    {
        if( (*tree)->left == NULL  )
        {
            temp = (*tree) ;
            (*tree) = (*tree)->right ;
            free(temp) ;
        }
        else if( (*tree)->right == NULL  )
        {
            temp = (*tree) ;
            (*tree) = (*tree)->right ;
            free(temp) ;
        }
        else
        {
            temp = minValue((*tree)->right);
            (*tree)->data = temp ->data ;
            deleteNode(&(*tree)->right,temp->data) ;

        }

    }
}


int main()
{
    bst *tree ;
    bst *ptr ;
    createEmpty(&tree);
    insertNode(&tree,10);
    insertNode(&tree,5);
    insertNode(&tree,4);
    insertNode(&tree,3);
    insertNode(&tree,15);
    insertNode(&tree,20);
    insertNode(&tree,30);
    cout << endl << "inOrderTraversal\n" ;
    inOrderTraversal(tree);
    cout << endl<< "preOrderTraversal \n" ;
    preOrderTraversal(tree);
    cout << endl <<"postOrderTraversal \n" ;
    postOrderTraversal(tree);
    cout <<"\n deleting 10  \n";
    deleteNode(&tree , 10) ;
    cout << "\ninOrderTraversal\n" ;
    inOrderTraversal(tree);
    cout << "\nlargest element is :\n"
       << maxValue(tree)->data;
    cout << "\nsmallest element is :\n"
       << minValue(tree)->data;
    getchar();
}
