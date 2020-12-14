
void inorderTraversalit(bst *tree)
{
    stack <bst* > S ;
    bst *temp ;

    while( S.empty() == false || tree != NULL  )
    {
        while(tree != NULL )
        {
            S.push(tree) ;
            tree = tree->left ;
        }
        tree = S.top() ;
        cout << "\t" << tree->data ;
        S.pop();
        tree = tree->right ;


    }

}
