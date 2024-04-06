class Trie {
    int prefixWords;
    vector<Trie*> children;
    bool isEnd;

public:
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

    int noOfPrefix(string word) {
        Trie* node = this;
        int totalNoOfPrefix = 0;
        for (auto &c: word) {
            if (node->children[c-'a'] == NULL) {
                return totalNoOfPrefix;
            }
            node = node->children[c-'a'];
            totalNoOfPrefix += node->prefixWords;
        }
        return totalNoOfPrefix;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        Trie* head = new Trie();
        for (auto &word: words) {
            head->insert(word);
        }

        for (auto &word: words) {
            res.push_back(head->noOfPrefix(word));
        }

        return res;
    }
};