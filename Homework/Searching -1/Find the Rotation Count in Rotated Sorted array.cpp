class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int s = 0, e = n-1;
	       
	    int currMin = 0;
	    while (s<=e) {
	        int mid = s + (e-s)/2;
	        
	        if (arr[mid] <= arr[currMin]) 
	            currMin = mid;
	       
	        if (arr[mid] < arr[e]) {
	            e = mid-1;
	        }
	        else
	            s = mid+1;
	        
	    }
	    return currMin;
	}

};