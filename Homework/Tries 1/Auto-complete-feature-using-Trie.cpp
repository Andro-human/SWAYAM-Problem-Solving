#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<string> &res) {
    for(auto &i: res) {
        cout << i << endl;
    }
}

class Trie {
    Trie* children[26];
    vector<int> pastSearches;

public:
    Trie(): children{NULL} {}

    void insert(string search, int idx) {
        Trie* node = this;
        for (int i=0; i<search.size(); i++) {
            if (node->children[search[i]-'a'] == NULL) {
                node->children[search[i]-'a'] = new Trie();
            }

            node = node->children[search[i] - 'a'];
            node->pastSearches.push_back(idx);
        }
    }

    void autoComplete(string s, vector<string> &searches) {
        Trie *node = this;
        for (int i=0; i<s.length(); i++) {
            if (node->children[s[i]-'a'] == NULL) {
                return;
            }
            node = node->children[s[i]-'a'];
        }

        vector<string> res;
        for (int i=0; i<node->pastSearches.size(); i++) {
            res.push_back(searches[node->pastSearches[i]]);
        }

        printVec(res);
    }
};


int main() {
    vector<string> searches {"hello", "dog", "hell", "cat", "a", "hel", "help", "helps", "helping"};
    
    Trie *node = new Trie();
    for (int i=0; i<searches.size(); i++) {
        node->insert(searches[i], i);
    }

    string s;
    cout << "Type a Query: ";
    cin >> s;

    node->autoComplete(s, searches);    
}