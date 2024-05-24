class Solution {
public:
    // DP
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp (n, 1);

    //     dp[0] = 1;
    //     for (int i=1; i<n; i++) {
    //         for (int j=0; j<i; j++) {
    //             if (nums[j] < nums[i]) dp[i] = max(dp[j]+1, dp[i]);
    //         }
    //     }

    //     return *max_element(dp.begin(), dp.end());
    // }

    // DP using BS
    int lowerBound(vector<int> vec, int num) {
        int s = 0, e = vec.size()-1;

        while (s<=e) {
            int mid = s+(e-s)/2;

            if (vec[mid] >= num) e = mid-1;
            else s = mid+1;
        }
        return s;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;

        vec.push_back(nums[0]);
        for (int i=1; i<n; i++) {
            if (nums[i] > vec.back()) {
                vec.push_back(nums[i]);
                continue;
            }
            else {
                // auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
                int idx = lowerBound(vec, nums[i]);
                vec[idx] = nums[i];
            }
        }

        return vec.size();        
    }
};