class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        int lastIdx = nums.size()-1;
        while (s<=e) {
            int mid = s+(e-s)/2;
            
            if (mid == 0) {
                if (mid+1<=lastIdx && nums[mid] > nums[mid+1])
                    return nums[mid+1];
                else 
                    return nums[mid];
            }

            if (mid == lastIdx) {
                return nums[mid];
            }

            if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid]+1)
                return nums[mid];

            if (nums[mid] < nums[lastIdx]) {
                e = mid-1;
            }

            else {
                s = mid+1;
            }
        }

        return -1;
    }
};