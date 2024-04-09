class Trie {
    int prefixWords;
    Trie* children[26];

public:
    Trie(): prefixWords{0}{
        memset(children, NULL, sizeof(children));
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