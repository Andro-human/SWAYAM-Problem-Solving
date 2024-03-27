class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return vector<int>{};

        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL) {
                if(!q.empty())
                    q.push(NULL);
                continue;
            }
            if (q.front() == NULL) {
                res.push_back(temp->val);
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        return res;
    }
};