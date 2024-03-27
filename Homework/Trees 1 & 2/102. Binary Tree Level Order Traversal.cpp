/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> vec;
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL) {
                res.push_back(vec);
                vec.clear();
                if (!q.empty())
                    q.push(NULL);
                continue;
            }

            if (temp->left!=NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);

            vec.push_back(temp->val);

        }
        return res;
    }
};