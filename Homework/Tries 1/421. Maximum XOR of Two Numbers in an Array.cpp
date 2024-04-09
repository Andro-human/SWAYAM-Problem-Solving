class Trie {
    vector<Trie*> children;
public:
    Trie(): children(2, NULL) {}

    void insert(int num) {
        Trie *node = this;
        for (int i=31; i>=0; i--) {
            int currBit = ((num >> i) & 1);
            if (node->children[currBit] == NULL) {
                node->children[currBit] = new Trie();
            }

            node = node->children[currBit];
        }
    }

    int xorFunc(int num) {
        Trie *node = this;
        int currXor = 0;
        for (int i=31; i>=0; i--) {
            int currBit = ((num >> i) & 1);
            if (node->children[!currBit] != NULL) {
                node = node->children[!currBit];
                currXor = ((currXor << 1) | 1);
            }
            else {
                node = node->children[currBit];
                currXor = (currXor << 1);
            }
        }

        return currXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *head = new Trie();
        for (auto &i: nums)
            head->insert(i);

        int res = 0;
        for (auto &i: nums) {
            res = max(head->xorFunc(i), res);
        }
        return res;
    }
};