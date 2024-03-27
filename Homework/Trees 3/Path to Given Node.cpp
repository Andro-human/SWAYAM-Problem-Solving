bool pathToNode(TreeNode *root, int B, vector<int> &res) {
    if (!root)
        return false;
    
    if (root->val == B) {
        res.push_back(B);
        return true;
    }
    bool x = pathToNode(root->left, B, res);
    bool y = pathToNode(root->right, B, res);
    
    if (x || y) {
        res.push_back(root->val);
        return true;
    }
        
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    
    pathToNode(A, B, res);
    
    reverse(res.begin(), res.end());
    return res;
}