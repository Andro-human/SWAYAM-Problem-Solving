class Solution
{
    public:
    vector<int> merge(Node *root1, Node *root2)
    {
       stack<Node*> s1, s2;
       vector<int> res;
       while (true) {
           while (root1) {
               s1.push(root1);
               root1 = root1->left;
           }
           while (root2){
               s2.push(root2);
               root2 = root2->left;
           }
           if (!s1.empty() && !s2.empty()) {
               root1 = s1.top(), root2 = s2.top();
                
                if (root1->data <= root2->data) {
                    res.push_back(root1->data);
                    s1.pop();
                    root1 = root1->right;
                    root2 = NULL;
                }
                else {
                    res.push_back(root2->data);
                    s2.pop();
                    root1 = NULL;
                    root2 = root2->right;
                } 
           }
           else if (!s1.empty()) {
               root1 = s1.top();
               res.push_back(root1->data);
               s1.pop();
               root1 = root1->right;
           }
           else if (!s2.empty()) {
               root2 = s2.top();
               res.push_back(root2->data);
               s2.pop();
               root2 = root2->right;
           }
           else 
               break;
       }
       
       return res;
    }
};