class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int curr_sum = 0;

        int min = nums[0];
        bool flag = false;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) {
                flag = true;
                break;
            }

            if (nums[i] > min)
                min = nums[i];
        }
        if (!flag) {
            return min;
        }
        
        for (int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            if (curr_sum > res) {
                res = curr_sum;
            }
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }

        return res;
    }
};