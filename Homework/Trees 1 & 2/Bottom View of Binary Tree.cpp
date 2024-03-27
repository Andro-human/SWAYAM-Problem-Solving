class Solution {
  private:
    void verticalOrder(Node *root, map<int, map<int,int>> &mp, int x, int y) {
        if (!root) {
            return;
        }
        
        mp[x][y] = root->data;
        verticalOrder(root->left, mp, x-1, y+1);
        verticalOrder(root->right, mp, x+1, y+1);
    }
  public:
    vector <int> bottomView(Node *root) {
        map<int, map<int, int>> mp;
        verticalOrder(root, mp, 0,0);
        
        vector<int> res;
        for (auto &i: mp) {
            int x = 0;
            for (auto &j: i.second) {
                x = j.second;
            }
            res.push_back(x);
        }
        
        return res;
    }
};