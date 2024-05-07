class Solution {
private:
    int lowerBound(vector<int> &heaters, int target) {
        int s = 0, e = heaters.size()-1;
        while (s<=e) {
            int mid = s + (e-s)/2;  
            if (heaters[mid] >= target) e = mid-1;
            else s = mid+1;
        }
        if (s >= heaters.size()) return heaters.size()-1;
        return s;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int maxDist = 0;
        for (int i=0; i<n; i++) {
            int x = 0;
            x = lowerBound(heaters, houses[i]);
            int nextBig = abs(heaters[x]-houses[i]);
            int prevBig = INT_MAX;
            if (x-1 >= 0) prevBig = houses[i]-heaters[x-1];
            maxDist = max(maxDist, min(nextBig, prevBig));
        }

        return maxDist;
    }
};