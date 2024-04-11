class Trie {
    int minElementIdx;
    int minElementSize;
    Trie* children[26];
public: 
    Trie(): minElementIdx{-1}, minElementSize{10000}, children{NULL} {}

    void insert(string &s, int &idx) {
        Trie *node = this;
        for (int i=s.length()-1; i>=0; i--) {
            if(node->children[s[i] - 'a'] == NULL) {
                node->children[s[i] - 'a'] = new Trie();
            }

            if (minElementIdx == -1 || node->minElementSize > s.length()) {
                node->minElementIdx = idx;
                node->minElementSize = s.length();
            }

            node = node->children[s[i] - 'a'];
        }
        if (node->minElementSize > s.length()) {
            node->minElementIdx = idx;
            node->minElementSize = s.length();
        }
    }

    int findSuffix(string &s) {
        Trie *node = this;
        for (int i=s.length()-1; i>=0; i--) {
            if (node->children[s[i]-'a'] != NULL) {
                node = node->children[s[i]-'a'];
            }
            else {
                return node->minElementIdx;
            }
        }
        return node->minElementIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie *node = new Trie();
        for (int i=0; i<wordsContainer.size(); i++) {
            node->insert(wordsContainer[i], i);
        }
        vector<int> res;
        for (int i=0; i<wordsQuery.size(); i++) {
            res.push_back(node->findSuffix(wordsQuery[i]));
        }

        return res;
    }
};