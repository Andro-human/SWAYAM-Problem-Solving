class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int>vec (amount+1, INT_MAX);
        vec[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int j=0; j<coins.size(); j++) {
                if (i-coins[j] >= 0 && vec[i-coins[j]] != INT_MAX) {
                    vec[i] = min(vec[i], vec[i-coins[j]]+1);
                }
            }
        }

        if (vec[amount] != INT_MAX)
            return vec[amount];

        return -1;
    }
};