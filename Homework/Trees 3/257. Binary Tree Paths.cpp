class Solution {
private: 
    void leafPath(TreeNode* root, string s, vector<string> &res) {
        if (!root) 
            return;

        if (!root->left && !root->right) {
            s += to_string(root->val);
            res.push_back(s);
            return; 
        }
        s += (to_string(root->val) + "->");
        leafPath(root->left, s, res);
        leafPath(root->right, s, res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        vector<string> res;
        leafPath(root, s, res);
        
        for (int i=0; i<res.size(); i++) 
            cout << res[i] << endl;
        
        return res;
    }
};