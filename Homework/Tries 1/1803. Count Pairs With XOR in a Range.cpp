class Trie {
    Trie *children[2];
    int numElements;

public:
    Trie(): children{NULL, NULL}, numElements{0} { }

    void insert(int num) {
        Trie *node = this;
        for (int i=15; i>=0; i--) {
            int currBit = ((num >> i) & 1);
            if (node->children[currBit] == NULL) {
                node->children[currBit] = new Trie();
            }
            node = node->children[currBit];
            node->numElements++;
        }
    }

    long long xorFunc(int num, int high) {
        Trie *node = this;
        long long totalNums = 0;
        for (int i=15; i>=0; i--) {
            int numBit = ((num >> i) & 1);
            int highBit = ((high >> i) & 1);
            if (highBit) {
                if (node->children[!numBit] != NULL) {
                    if (node->children[numBit] != NULL) {
                        totalNums += node->children[numBit]->numElements;
                    }
                    node = node->children[!numBit];
                }
                else {
                    return (totalNums += node->children[numBit]->numElements);
                }
            }
            else if (node->children[numBit] != NULL){
                node = node->children[numBit];
            }
            else {
                return totalNums;
            }
        }

        return totalNums+node->numElements;
    }
};


class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie *tree = new Trie();

        for (auto &i: nums) {
            tree->insert(i);
        }
        long long res = 0;
        for (auto &i: nums) {
            res += tree->xorFunc(i, high);
            res -= tree->xorFunc(i, low-1);
        }


        return res/2;
    }
};