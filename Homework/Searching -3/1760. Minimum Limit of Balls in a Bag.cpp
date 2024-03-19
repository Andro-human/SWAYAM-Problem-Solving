class Solution {
private: 
    bool isPossible(int mid, int k, vector<int> nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < mid)
                continue;
            if (nums[i]%mid != 0)
                res += (nums[i]/mid);
            else
                res += (nums[i]/mid)-1;
        }
        if (res <= k) {
            return true;
        }
        return false;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1;
        int e= *max_element(nums.begin(), nums.end());
        if (e == 0) {
            return 0;
        }
        while (s<=e) {
            int mid = s + (e-s)/2;
            cout << mid << endl;
            if (isPossible(mid, maxOperations, nums)) {
                e = mid-1;
            }
            else 
                s = mid+1;
        }
        
        return s;
    }
};