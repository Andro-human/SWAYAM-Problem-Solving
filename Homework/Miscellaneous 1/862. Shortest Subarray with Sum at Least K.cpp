class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,int>> dq;
        dq.push_back({0, -1});
        int res = INT_MAX;
        long long currSum = 0;
        for (int i=0; i<nums.size(); i++) {
            currSum += nums[i];

            while (!dq.empty() && currSum-k >= dq.front().first) {
                res = min(res, i-dq.front().second);
                dq.pop_front();
            }

            while (!dq.empty() && currSum <= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({currSum,i});
        }
        
        if (res == INT_MAX) return -1;
        return res;
    }
};