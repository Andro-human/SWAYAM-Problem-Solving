class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cummul1 = 1;
        int ans1 = INT_MIN;
        int cummul2 = 1;
        int ans2 = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            cummul1 = cummul1*nums[i];
            ans1 = max(ans1, cummul1);
            if (cummul1 == 0) {
                cummul1 = 1;
            }
            cummul2 = cummul2*nums[nums.size()-i-1];
            ans2 = max(ans2, cummul2);
            if (cummul2 == 0) {
                cummul2 = 1;
            }
        }
        return max(ans1, ans2);
    }
};