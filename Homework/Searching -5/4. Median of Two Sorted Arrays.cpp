class Solution {
public:
    double findMedian(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size())
            return findMedian(nums2, nums1, k);
        
        int s = 0, e = nums1.size();
        while (s<=e) {
            int mid = s + (e-s)/2;

            int l1 = INT_MIN, l2 = INT_MIN;
            if (mid-1 >= 0) 
                l1 = nums1[mid-1];
            if (k-mid-1 >= 0)
                l2 = nums2[k-mid-1];
            
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid < nums1.size())
                r1 = nums1[mid];
            if (k-mid < nums2.size())
                r2 = nums2[k-mid];

            if (l1 <= r2 && l2 <= r1) {
                if ((nums1.size()+nums2.size())%2 == 0) {
                    int x = max(l1, l2);
                    int y = min(r1, r2);
                    return (double)(x+y)/2.0;
                }
                return max(l1, l2);
            }
            else if (l1 > r2) {
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        return findMedian(nums1,nums2, (n+1)/2);
    }
};