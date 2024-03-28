int heightOfBinaryTree(TreeNode<int> *root)
{
	if (!root)
        return 0;
    
    int x = heightOfBinaryTree(root->left);
    int y = heightOfBinaryTree(root->right);

    return max(x, y) + 1;
}