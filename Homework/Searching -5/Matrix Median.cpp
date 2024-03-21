int elemsBefore(int val, vector<vector<int>> &A, int n11, int n12) {
    int res = 0;
    for (int i=0; i<n11; i++) {
        int s = 0, e = n12-1;
        while (s<=e) {
            int mid = s + (e-s)/2;
            
            if (A[i][mid] > val) {
                e = mid-1;
            }
            else 
                s = mid+1;
        }
        res += s;
    }
    return res;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int s = INT_MAX, e = INT_MIN;
    int n11 = A.size(), n12 = A[0].size();
    for (int i=0; i<n11; i++) {
        s = min(s, A[i][0]);
        e = max(e, A[i][n12-1]);
    }
    
    int k = (n11*n12/2);
    while (s<=e) {
        int mid = s + (e-s)/2;
        
        int numElems = elemsBefore(mid, A, n11, n12);
        if (numElems-1 >= k) {
            e = mid-1;
        }
        else
            s = mid+1;
    }
    
    return s;
}
