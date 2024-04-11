class Trie {
    bool isEnd;
    Trie* children[26];

public:
    Trie(): isEnd{false}, children{NULL} {

    };

    void insert(string s) {
        Trie* node = this;
        for (int i=0; i<s.length(); i++) {
            if (node->children[s[i]-'a'] == NULL) {
                node->children[s[i]-'a'] = new Trie();
            }

            node = node->children[s[i]-'a'];
        }
        node->isEnd = true;
    }

    string replaceWord(string s) {
        Trie *node = this;
        string res;
        for (int i=0; i<s.length(); i++) {
            if (node->children[s[i] - 'a'] != NULL) {
                res += s[i];
                node = node->children[s[i] - 'a'];
                if (node->isEnd) {
                    return res;
                }
            }

            else 
                return s;
        }

        return s;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *node = new Trie();
        for (auto &i: dictionary) {
            node->insert(i);
        }

        string res;
        string currString;
        for (int i=0; i<sentence.length(); i++) {
            if(sentence[i] == ' ') {
                res += node->replaceWord(currString) + " ";
                currString = "";
                continue;
            }
            currString += sentence[i];
        }
        res += node->replaceWord(currString);
        
        return res;
    }
};