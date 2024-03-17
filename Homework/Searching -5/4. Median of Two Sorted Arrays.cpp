class Solution {
private:
    int findElems(vector<int> nums, int value) {
        int s = 0, e = nums.size()-1;

        while (s<=e) {
            int mid = s + (e-s)/2;

            if (nums[mid] == value) {
                if (mid == 0) {
                    return 0;
                }
                return mid;
            }
            else if (nums[mid] < value) {
                s = mid+1;
            }
            else 
                e = mid-1;
        }

        return s;
    }
    int findMedian(vector<int> nums1, vector<int> nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        int s = min(nums1[0], nums2[0]);
        int e = max(nums1[n-1], nums2[m-1]);
        while (s<=e) {
            int mid = s + (e-s)/2;
            int elemsInA = findElems(nums1, mid);
            int elemsInB = findElems(nums2, mid);
            if (elemsInA+elemsInB <= k)
                s = mid+1;
            else
                e = mid-1;
        }

        return s-1;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int k = (n1+n2)/2;
        if (n1 == 0) {
            if (n2%2 == 1)
                return nums2[k];
            else 
                return (double)(nums2[k]+nums2[k-1])/2;
        }
        if (n2 == 0) {
            if (n1%2 == 1)
                return nums1[k];
            else 
                return (double)(nums1[k]+nums1[k-1])/2;
        };
        if ((n1+n2)%2 == 1) {
            return findMedian(nums1, nums2, k);
        }
        else {
            double x = findMedian(nums1, nums2, k);
            double y = findMedian(nums1, nums2, k-1);
            return (x+y)/2;
        }
        return 0;
    }
};