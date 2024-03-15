class Solution {
private:
    bool isPossible(int mid, string s, string t, int maxCost) {
        int curr = 0;
        for (int i=0; i<mid; i++) 
             curr += abs(s[i] - t[i]);
        
        int st = 0;
        for (int i = mid; i<s.length(); i++) {
            if (curr <= maxCost)
                return true;
            
            curr += abs(s[i] - t[i]);
            curr -= abs(s[st] - t[st]);
            st++;
        }
        if (curr <= maxCost)
            return true;
        return false;
    }
public:
    int equalSubstring(string s, string t, int maxCost) {    
        int st = 0, e = s.length();
        int mid = 0;
        int res = 0;
        while (st<=e) {
            int mid = st + (e-st)/2;

            if (isPossible(mid, s, t, maxCost)) {
                res = mid;
                st = mid+1;
            }
            else 
                e = mid-1;
        } 

        return res;
    }
};