class Solution {
private:
    TreeNode *createBST(vector<int> &vec, int s, int e) {
        if (s > e)
            return NULL;

        int mid = s + (e-s)/2;
        TreeNode *tree = new TreeNode(vec[mid]);
        
        tree->left= createBST(vec, s, mid-1);
        tree->right = createBST(vec, mid+1, e);
        
        return tree;
    }

    void input(vector<int> &vec, ListNode *head) {
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        input(vec, head);
        return createBST(vec, 0, vec.size()-1);
    }
};