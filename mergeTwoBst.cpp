#include<iostream>
using namespace std ;

struct bst
{
    int info ;
    struct bst* left ;
    struct bst* right ;
};
typedef struct bst bst ;

struct lList{
    int info ;
    struct lList *next ;

};
typedef struct lList lList ;

void insertNode(bst** tree , int data)
{
    bst* ptr ;
    ptr = (bst* )malloc(sizeof(bst)) ;
    ptr->info = data ;
    ptr->left = NULL ;
    ptr->right = NULL ;
    if( *tree == NULL )
    {
        *tree = ptr ;
        return ;
    }
    bst* node ;
    bst* parent = NULL ;
    node = (*tree) ;
    while( node != NULL  )
    {
        parent = node ;
        if( data > node->info )
            node = node->right ;
        else
            node = node->left ;
    }
    if( data > parent->info )
        parent->right = ptr ;
    else
        parent->left = ptr ;
}

void createList(int data ,lList **head )
{
    lList *ptr ;
    ptr = (lList* )malloc(sizeof(lList)) ;
    ptr->info = data ;
    ptr->next = NULL ;
    if((*head) == NULL )
        (*head) = ptr ;
    else{
        lList *ptr2 = *head ;

        while( ptr2->next != NULL )
            ptr2= ptr2->next ;
            ptr2->next = ptr ;
    }



}

void inOrderTraversal(bst* tree , lList **head )
{
    if( tree != NULL  )
    {
        inOrderTraversal(tree->left , head ) ;
        createList(tree->info , head ) ;
        inOrderTraversal(tree->right , head) ;
    }

}


void traverse(lList *head)
{
    while( head != NULL  )
    {
        cout <<head->info << "\t" ;
        head = head->next ;
    }

}
lList* mergeList( lList* head1 , lList* head2)
{
    lList* head = NULL  ;
    while( (head1 != NULL) && (head2 != NULL ) )
    {
        if( head1->info < head2->info){
            createList( head1->info , &head ) ;
            head1 = head1->next ;
        }
        else{
            createList( head2->info , &head ) ;
            head2 = head2->next ;
        }
    }
    if( head1 == NULL  )
    {
        while(head2 != NULL)
        {
            createList( head2->info , &head ) ;
            head2 = head2->next ;
        }
    }
    else if( head2 == NULL  )
    {
        while(head1 != NULL)
        {
            createList( head1->info , &head ) ;
            head1 = head1->next ;
        }
    }
    return head ;
}

int main()
{
    bst *tree ;
    lList *head ;
    head = NULL ;

    bst *tree1 ;
    lList *head1 ;
    head1 = NULL ;

    tree = NULL ;
    tree1 = NULL ;
    insertNode(&tree,50) ;
    insertNode(&tree1,5) ;

    insertNode(&tree,40) ;
    insertNode(&tree1,4) ;
    insertNode(&tree1,6) ;
    insertNode(&tree,60) ;
    insertNode(&tree,35) ;
    insertNode(&tree1,3) ;
    insertNode(&tree,45) ;
    insertNode(&tree,55) ;
    insertNode(&tree,65) ;
    inOrderTraversal(tree , &head) ;
    inOrderTraversal(tree1 , &head1) ;
    traverse(head) ;
    cout <<"\n" ;
    traverse(head1) ;

    lList *head3 = mergeList(head ,head1) ;
     cout <<"\n" ;
    traverse(head3) ;
    return 0 ;
}

