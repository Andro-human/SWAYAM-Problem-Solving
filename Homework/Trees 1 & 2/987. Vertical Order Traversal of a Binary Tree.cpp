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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int,int>>> mp;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            mp[x].insert({y, node->val});
            q.pop();

            if (node->left) {
                q.push({node->left, {x-1,y+1}});
            }
            if (node->right)
                q.push({node->right, {x+1, y+1}});
        } 

        vector<vector<int>> res;
        for (auto &i: mp) {
            vector<int> vec;
            for (auto &j: i.second) {
                vec.push_back(j.second);
            }
            res.push_back(vec);
        }

        return res;
    }
};