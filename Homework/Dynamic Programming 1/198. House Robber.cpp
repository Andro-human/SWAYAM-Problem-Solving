class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int secondPrev = nums[0];
        int prev = max(secondPrev, nums[1]);
        for (int i=2; i<n; i++) {
            int temp = max(prev, secondPrev+nums[i]);
            secondPrev = prev;
            prev = temp;
        }

        return prev;
    }
};