class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        int last = nums.size()-1;
        while (s<=e) {
            int mid = s + (e-s)/2;
            if (nums[mid] == target)
                return true;
            
            if (nums[mid] == nums[s] && nums[mid] == nums[e]) {
                s = s+1;
                e = e-1;
            }
            else if (nums[mid] > nums[e]) {
                if (nums[mid] < target || (nums[mid] > target && target <= nums[e]))
                    s = mid+1;
                else 
                    e = mid-1;
            }
           
            else {         
                if (nums[mid] > target || (nums[mid] < target && target > nums[e])) {
                    e = mid-1;
                }
                else 
                    s = mid+1;
            }
        }

        return false;
    }
};