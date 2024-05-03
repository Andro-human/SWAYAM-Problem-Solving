class Solution {
    int houseRob(vector<int>& nums, int i, int n) {
        if (n-i == 1) return nums[i];
        
        int secondPrev = nums[i];
        int prev = max(secondPrev, nums[i+1]);
        i+=2;
        while (i < n) {
            int temp = max(prev, secondPrev+nums[i]);
            secondPrev = prev;
            prev = temp;
            i++;
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int notTakeFirst = houseRob(nums, 1, n);
        int notTakeLast = houseRob(nums, 0, n-1);

        return max(notTakeFirst, notTakeLast); 
    }
};