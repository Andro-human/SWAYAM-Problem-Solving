void printLeft(BinaryTreeNode<int> *root, int level , vector<int> &res) {
    if (!root)
        return;
    
    if (level > res.size()) {
        res.push_back(root->data);
    }
    printLeft(root->left, level+1, res);
    printLeft(root->right, level+1, res);        
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> res;
    printLeft(root, 1, res);
    return res;
}