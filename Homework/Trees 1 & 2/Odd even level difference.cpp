class Solution{
  private:
    void getLevel (Node *root, int &oddSum, int &evenSum, int level) {
        if (!root)
            return;
        
        if (level%2) {
            oddSum += root->data;
        }
        else
            evenSum += root->data;
        
        getLevel(root->left, oddSum, evenSum, level+1);
        getLevel(root->right, oddSum, evenSum, level+1);
    }
  public:
    
    int getLevelDiff(Node *root)
    {
        int oddSum = 0, evenSum = 0;
        getLevel(root, oddSum, evenSum, 1);
        
        return oddSum-evenSum;
    }
};