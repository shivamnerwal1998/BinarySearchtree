
void levelOrderTraversal(bst *tree)
{
    queue <bst *> q ;
    q.push(tree) ;
    while( q.empty() == false )
    {

        bst *temp = q.front() ;
        cout << temp->data << " " ;

        q.pop() ;

        if( temp->left != NULL )
            q.push( temp->left ) ;
        if( temp->right != NULL  )
            q.push(temp->right) ;

    }

}

