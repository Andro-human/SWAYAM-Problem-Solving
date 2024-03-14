class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        if (nums.size() == 1)  
            return nums[0];
        
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[e] != nums[e-1]) {
            return nums[e];
        }

        while (s<=e) {
            int mid = s + (e-s)/2;

            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }
            else if ((!(mid%2) && nums[mid] != nums[mid+1]) || (mid%2 && nums[mid] != nums[mid-1])) {
                e = mid-1;
            }
            else 
                s = mid+1;
        }
        return -1;
    }
};