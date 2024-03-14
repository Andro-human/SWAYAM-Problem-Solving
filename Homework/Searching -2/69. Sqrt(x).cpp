class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int s = 1, e = x/2;
        int res = 0; 
        while (s<=e) {
            int mid = s + (e-s)/2;

            if ((long long)mid*mid <= x) {
                res = mid;
                s = mid+1;
            }
            else 
                e = mid-1;
        }
        return res;
    }
};