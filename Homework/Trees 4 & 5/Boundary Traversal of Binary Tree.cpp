void findLeft(TreeNode<int> *root, vector<int> &left) {
    if (!root->left) {
        left.push_back(root->data);
        return;
    }
    while (root) {
      while (root->left) {
        left.push_back(root->data);
        root = root->left;
      }
      if (root->right)
        left.push_back(root->data);
      root = root->right;
    }
}

void findRight(TreeNode<int> *root, vector<int> &right) {
    if (!root->right) {
      return;
    }
    while (root) {
        while (root->right) {
            right.push_back(root->data);
            root = root->right;
        }
        if (root->left)
            right.push_back(root->data);
        root = root->left;
    }
}

void findLeaf(TreeNode<int> *root, vector<int> &leafNodes) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        leafNodes.push_back(root->data);
        return;
    }

    findLeaf(root->left, leafNodes);
    findLeaf(root->right, leafNodes);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> leftBoundary;
    vector<int> rightBoundary;
    vector<int> leafNodes;

    findLeft(root, leftBoundary);
    findRight(root, rightBoundary);
    findLeaf(root, leafNodes);

    vector<int> res;

    for(int i=0; i<leftBoundary.size(); i++) {
        res.push_back(leftBoundary[i]);
    }

    for(int i=0; i<leafNodes.size(); i++) {
        res.push_back(leafNodes[i]);
    }

    for (int i=rightBoundary.size()-1; i>0; i--) {
        res.push_back(rightBoundary[i]);
    }

    return res;
}