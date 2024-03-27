/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) {
                res += "$,";
                continue;
            }
            res += to_string(node->val);
            res += ",";

            q.push(node->left);
            q.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.length())
            return NULL;
        
        string s;
        int i=0;
        while (data[i] != ',') {
            s += data[i++];
        }
        i++;
        TreeNode *head = new TreeNode(stoi(s));

        queue<TreeNode*> q;
        q.push(head);
        while (!q.empty()) {
            if (i >= data.length()) {
                break;
            }
            TreeNode *node = q.front();
            q.pop();
            
            s.clear();
            while (data[i] != ',') {
                s += data[i++];
            }
            i++;
            if (s == "$") {
                node->left = NULL;
            }
            else {
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }
            s.clear();
            while (data[i] != ',') {
                s += data[i++];
            }
            i++;
            if (s == "$") {
                node->right = NULL;
            }
            else {
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }

        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));