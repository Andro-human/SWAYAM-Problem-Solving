int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int x = findCeil(root->left, input);
    
    if (x != -1)
        return x;
        
    if (root->data >= input)
        return root->data;
    
    return findCeil(root->right, input);

}