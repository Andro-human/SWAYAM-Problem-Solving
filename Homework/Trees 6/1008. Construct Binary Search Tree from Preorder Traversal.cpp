class Solution {
private:
    int lowerBound(vector<int>& preOrder, int target) {
        int l = target+1, h = preOrder.size()-1;
        while (l<=h) {
            int mid = l + (h-l)/2;
            if (preOrder[target] > preOrder[mid])
                l = mid+1;
            
            else 
                h = mid-1;
        }
 
        return l;
    }
    TreeNode *buildBST(vector<int>& preOrder, int idx, vector<bool> &visited) {
        if (idx >= preOrder.size()) {
            return NULL;
        }

        TreeNode *tree = new TreeNode(preOrder[idx]);

        int lb = lowerBound(preOrder, idx);
        bool flag = false;
        if (lb < preOrder.size() && !visited[lb]) {
            flag = true;
            visited[lb] = true;
        }
        
        if (idx+1 < preOrder.size() && preOrder[idx+1] < preOrder[idx])
            tree->left = buildBST(preOrder, idx+1, visited);
        else tree->left = NULL;

        if (!flag)
            tree->right = NULL;
        else tree->right = buildBST(preOrder, lb, visited);

        return tree;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (!preorder.size())
            return NULL;
        vector<bool> visited (preorder.size(), false);
        visited[0] = true;
        return buildBST(preorder, 0, visited);
    }
};