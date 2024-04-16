class Trie {
    Trie* children[26];
    vector<string> words;
    
public:
    Trie(): children{NULL} {}
    
    void insert(string s) {
        Trie *node = this;
        for (int i=0; i<s.length(); i++) {
            if (node->children[s[i]-'a'] == NULL) {
                node->children[s[i]-'a'] = new Trie();
            }
            node = node->children[s[i]-'a'];
            node->words.push_back(s);
        }
    }
    
    void autoFill(string query, vector<vector<string>> &res) {
        Trie *node = this;
        int i=0;
        while (i<query.length()) {
            if (node->children[query[i] -'a'] != NULL) {
                node = node->children[query[i] -'a'];
                res.push_back(node->words);
            }
            else {
                break;
            }
            i++;
        }
        
        while (i<query.length()) {
            res.push_back({"0"});
            i++;
        }
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *node = new Trie();
        set<string> stringSet;
        for (int i=0; i<n; i++) {
            if (stringSet.find(contact[i]) == stringSet.end())
                node->insert(contact[i]);
            stringSet.insert(contact[i]);
        }        
        vector<vector<string>> res;
        node->autoFill(s, res);
        
        string temp = "0";
        for (auto &i: res) {
            sort(i.begin(), i.end());
        }
        return res;
    }
};