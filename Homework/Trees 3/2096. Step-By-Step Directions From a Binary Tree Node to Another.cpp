class Solution {
    TreeNode* lowestAnces(TreeNode* root, int startValue, int destValue) {
        if (!root)
            return NULL;

        if (root->val == startValue || root->val == destValue) {
            return root;
        }

        TreeNode *left = lowestAnces(root->left, startValue, destValue);
        TreeNode *right = lowestAnces(root->right, startValue, destValue);

        if (left && right)
            return root;
        
        if (left)
            return left;
        
        if (right)
            return right;

        return NULL;
    }

    bool findPath(TreeNode *A, int B, string &s) {
        if (!A)
            return false;
        if (A->val == B) {
            return true;
        }
        if (findPath(A->left, B, s)) {
            s += 'L';
            return true;
        }
        
        if (findPath(A->right, B, s)) {
            s += 'R';
            return true;
        }
        
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowestAncestor = lowestAnces(root, startValue, destValue);
        string s1, s2;
        findPath(lowestAncestor, startValue, s1);
        findPath(lowestAncestor, destValue, s2);
        for (int i=0; i<s1.length(); i++) {
            s1[i] = 'U';
        }
        reverse(s2.begin(), s2.end());
        return s1+s2;
    }
};