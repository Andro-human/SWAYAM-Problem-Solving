class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumpDist = 0;
        int cnt = 0;
        for (int i=0; i<nums.size()-1; i++) {
            if (jumpDist >= n-i-1) return cnt;
            if (jumpDist < nums[i]) {
                jumpDist = nums[i];
                cnt++;   
            }
            jumpDist--;
        }

        return cnt;
    }
};