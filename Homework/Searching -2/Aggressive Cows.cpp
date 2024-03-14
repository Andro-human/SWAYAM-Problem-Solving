class Solution {
private:
    bool isPossible(int diff, int cows, vector<int> &stalls) {
        int cowNums = 1, last = 0;
        for (int i=1; i<stalls.size(); i++) {
            if (stalls[i]-stalls[last] >= diff) {
                cowNums++;
                last = i;
            }
            if (cowNums >= cows) {
                return true;
            }
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(), stalls.end());
        
        int s = 1, e = stalls[n-1]-stalls[0];
        int ans = -1;
        while (s<=e) {
            int mid = s + (e-s)/2;
            if (isPossible(mid, k, stalls)) {
                ans = mid;
                s = mid+1;
            }
            else 
                e = mid-1;
        }
        
        return ans;
    }
};
