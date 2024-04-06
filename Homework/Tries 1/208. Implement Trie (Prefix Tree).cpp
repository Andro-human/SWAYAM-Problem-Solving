class Trie {
public:
    int prefixWords;
    vector<Trie*> children;
    bool isEnd;

    Trie(): isEnd{false}, prefixWords{0}{
        children.resize(26, NULL);
    }
    
    void insert(string word) {   
        Trie *node = this;  
        for (auto &c: word) {
            if (node->children[c-'a'] == NULL) {
                node->children[c-'a'] = new Trie();
            }

            node = node->children[c-'a'];
            node->prefixWords++;
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie *node = this;
        for (auto &c: word) {
            if (node->children[c-'a'] == NULL) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto &c: prefix) {
            if (node->children[c-'a'] == NULL) {
                return false;
            }
            node = node->children[c-'a'];
        }
        return node->prefixWords;
    }
};