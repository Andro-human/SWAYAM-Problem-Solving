class TreeInfo {
public:
    bool isBst;
    int minVal;
    int maxVal;
    int height;
    TreeInfo (bool isB, int mini, int maxi, int h): isBst{isB}, minVal{mini}, maxVal{maxi}, height{h} {}
};

class Solution{
    private:
    TreeInfo* largest(Node *root) {
        if (!root) {
            return new TreeInfo(true, INT_MAX, INT_MIN, 0);
        }
        
        TreeInfo *x = largest(root->left);
        TreeInfo *y = largest(root->right);
        
        if (x->isBst && y->isBst && root->data > x->maxVal && root->data < y->minVal) {
            return new TreeInfo(true, min(root->data, x->minVal) , max(root->data, y->maxVal), x->height+y->height+1);
        }
        if (x->height > y->height)
            return new TreeInfo(false, x->minVal, x->maxVal, x->height);
        
        return new TreeInfo(false, y->minVal, y->maxVal, y->height);
    }
    public:
    int largestBst(Node *root)
    {
    	return largest(root)->height;
    	
    }
};