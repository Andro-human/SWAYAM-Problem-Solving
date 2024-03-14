class Solution{
private:

	public:
	int NthRoot(int n, int m)
	{
	    if (m == 0 || m == 1 || n == 1) {
	        return m;
	    }
        
	    int s=1, e = 1;
        for (long long i=1; i<=m; i*=2) {
            long long power = pow(i, n);
            if (power > m) {
                e = i;
                break;
            }
        }
	    while (s<=e) {  
	        long long mid = s + (e-s)/2;
	        
	        long long num = pow(mid,n);
	        if (num == m) {
	            return mid;
	        }
	        else if (num > m) {
	            e = mid-1;
	        }
	        else 
	            s = mid+1;
	    }
	    
	    return -1;
	}  
};