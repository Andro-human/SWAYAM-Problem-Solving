class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            Node *node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (mp.find(level) == mp.end()) {
                mp[level] = node->data;
            }
            
            if (node->left)
                q.push({node->left, level-1});
            
            if (node->right)
                q.push({node->right, level+1});
        }
        
        vector<int> res;
        for (auto &i: mp) {
            res.push_back(i.second);
        }
        
        return res;
    }

};