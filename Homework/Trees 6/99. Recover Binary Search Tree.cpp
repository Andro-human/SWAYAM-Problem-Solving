class Solution {
private:
    void inOrder(TreeNode* root, TreeNode* &prev, TreeNode* &firstElem, TreeNode* &secondElem) {
        if (!root) {
            return;
        }

        inOrder(root->left, prev, firstElem, secondElem);

        if (root->val < prev->val) {
            if (!firstElem)
                firstElem = prev;
                
            secondElem = root;
        }
        prev = root;
        inOrder(root->right, prev, firstElem, secondElem);
    }

    void swap(TreeNode* firstElem, TreeNode* secondElem) {
        int temp = firstElem->val;
        firstElem->val = secondElem->val;
        secondElem->val = temp;
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* firstElem = NULL, *secondElem = NULL;
        TreeNode* prev = new TreeNode(INT_MIN);
        inOrder(root, prev, firstElem, secondElem);

        swap(firstElem, secondElem);
    }
};