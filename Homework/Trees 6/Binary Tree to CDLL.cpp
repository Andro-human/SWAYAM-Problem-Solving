class Solution
{
  private:
    Node *combineLists(Node *leftTree, Node *rightTree) {
        if (!leftTree)
            return rightTree;
        if (!rightTree)
            return leftTree;
            
        Node* temp = leftTree->left;
        leftTree->left->right = rightTree;
        leftTree->left = rightTree->left;
        
        rightTree->left->right = leftTree;
        rightTree->left = temp;
        
        return leftTree;
    }

  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        if (!root)
            return NULL;
            
        Node *leftSubTree = bTreeToCList(root->left);
        Node *rightSubTree = bTreeToCList(root->right);
        
        root->left = root;
        root->right = root;
        
        Node* List = combineLists(leftSubTree, root);
        List = combineLists(List, rightSubTree);

        return List;
    }
};