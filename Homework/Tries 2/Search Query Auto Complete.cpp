bool myComparator (pair<int, string> &p1, pair<int, string> &p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}  

class Trie {
    Trie* child[27];
    unordered_map<string, int> um;
    
public:
    Trie(): child{NULL} {}
    
    void insert(string &s, int freq) {
        Trie *node = this;
        for (int i=0; i<s.length(); i++) {
            int x = s[i]-'a';
            if (x == -65) x = 26;
            if (node->child[x] == NULL) {
                node->child[x] = new Trie();
            }
            node = node->child[x];
            node->um[s] += freq;
        }
    }
    
    Trie* search(char &c, vector<pair<int, string>> &words) {
        Trie *node = this;
        int x = c-'a';
        if (x == -65) x = 26;
        if (node->child[x] == NULL) {
            return NULL;
        }
        node = node->child[x];
        
        for (auto &i: node->um) {
            words.push_back({i.second, i.first});
        }
        
        sort(words.begin(), words.end(), myComparator);
        return node;
    }
};

class AutoCompleteSystem {
    Trie* root;
    string currString;
    Trie *currChar;
    
public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        currChar = root;
        for (int i=0; i<sentences.size(); i++) {
            root->insert(sentences[i], times[i]);
        }
    }
    vector<string> input(char c) {
        if (c == '#') {
            root->insert(currString, 1);
            currString = "";
            currChar = root; 
            return {};
        }
        currString += c;
        
        
        vector<pair<int, string>> words;
        vector<string> res;
        if (currChar == NULL) {
            return res;
        }
        
        currChar = currChar->search(c, words);

        for (int i=0, j=0; i<3 && j<words.size(); i++, j++) {
            res.push_back(words[i].second);
        }
        return res;
    }
};
