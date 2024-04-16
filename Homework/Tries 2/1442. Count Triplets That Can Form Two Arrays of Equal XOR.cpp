class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        um[0] = 1;
        int iXor = 0;
        int cnt = 0;
        for (int i=0; i<n-1; i++) {
            iXor ^= nums[i];
            int jXor = 0;
            for (int j=i+1; j<n; j++) {
                jXor ^= nums[j];
                if (um.find(iXor^jXor) != um.end()) {
                    cnt += um[iXor^jXor];
                }
            }   
            um[iXor]++;
        }
        return cnt;
    }
};