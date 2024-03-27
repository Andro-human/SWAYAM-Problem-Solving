/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int heightOfBinaryTree(TreeNode<int> *root)
{
	if (!root)
        return 0;
    
    int x = heightOfBinaryTree(root->left);
    int y = heightOfBinaryTree(root->right);

    return max(x, y) + 1;
}