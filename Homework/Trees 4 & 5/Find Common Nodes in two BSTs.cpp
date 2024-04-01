class Solution
{
    public:
    vector <int> findCommon(Node *root1, Node *root2)
    {
      stack<Node*> s1, s2;
      vector<int> res;
      
      while (true) {
          if (root1) {
            s1.push(root1);
            root1 = root1->left;
          }
          else if (root2) {
            s2.push(root2);
            root2 = root2->left;
          }
          else if (!s1.empty() && !s2.empty()) {
            root1 = s1.top(), root2 = s2.top();
            
            
            if (root1->data == root2->data) {
                res.push_back(root1->data);
                root1 = root1->right; 
                root2 = root2->right;
                s1.pop();
                s2.pop();
            }
            
            else if (root1->data < root2->data) {
                root1 = root1->right;
                root2 = NULL;
                s1.pop();
            }
            
            else {
                root2 = root2->right;
                root1 = NULL;
                s2.pop();
            }
          }
          
          else 
            break;  
      }
      
      return res;
     
    }
};