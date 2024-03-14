class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size()-1;
        int s = 1, e = n-1;
        if (n == 0 || nums[0] > nums[1])
            return 0;
        if (nums[n] > nums[n-1]) {
            return n;
        }
        while (s<=e) {
            int mid = s+(e-s)/2;
            
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if (nums[mid] > nums[mid-1]) {
                s = mid+1;
            }
            else 
                e = mid-1;

        }
        return -1;
    }
};