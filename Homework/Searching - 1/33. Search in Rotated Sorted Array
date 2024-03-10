class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int lastIdx = nums.size()-1;
        while (s<=e) {
            int mid = (e-s)/2+s;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] < nums[lastIdx]) {
                if (target > nums[mid] && target <= nums[lastIdx]) {
                    s = mid+1;
                }
                else 
                    e = mid-1;
            }

            else {
                if (target < nums[mid] && target > nums[lastIdx])
                    e = mid-1;
                else 
                    s = mid+1;
            }
        }

        return -1;
    }
};