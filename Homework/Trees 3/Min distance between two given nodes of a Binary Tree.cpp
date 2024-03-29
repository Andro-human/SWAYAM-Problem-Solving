class Solution{
    private:
      Node* lowestAnces(Node* root, int startValue, int destValue) {
        if (!root)
            return NULL;

        if (root->data == startValue || root->data == destValue) {
            return root;
        }

        Node *left = lowestAnces(root->left, startValue, destValue);
        Node *right = lowestAnces(root->right, startValue, destValue);

        if (left && right)
            return root;
        
        if (left)
            return left;
        
        if (right)
            return right;

        return NULL;
    }
    
    bool findDistance(Node* root, int target, int &distance) {
        if (!root)
            return false;
            
        if (root->data == target) {
            return true;
        }
        
        if (findDistance(root->left, target, distance)) {
            distance += 1;
            return true;
        }
        if (findDistance(root->right, target, distance)) {
            distance += 1;
            return true;
        }
        
        return false;
        
    }
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node *lowestAncestor = lowestAnces(root, a, b);
        
        int distance = 0;
        findDistance(lowestAncestor, a, distance);
        findDistance(lowestAncestor, b, distance);
        
        return distance;
        
    }
};