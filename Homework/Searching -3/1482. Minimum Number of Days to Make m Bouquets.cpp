class Solution {
private: 
    bool isPossible(int val, vector<int> &bloomDay, int m, int k) {
        int cnt = 0;
        int numBouquets = 0;
        for (int i=0; i<bloomDay.size(); i++) {
            if (bloomDay[i] <= val) {
                cnt++;
            }
            else {
                numBouquets += cnt/k;
                cnt = 0;
            }
        }
        numBouquets += cnt/k;
        return numBouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m*k)
            return -1;
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        while (s<=e) {
            int mid = s + (e-s)/2;
            if (isPossible(mid, bloomDay, m, k)) {
                e = mid-1;
            }
            else
                s = mid+1;
        }

        return s;
    }
};