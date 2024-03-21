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

int findKth(vector<int> nums1, vector<int> nums2, int k) {
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

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
        return findKth(arr1, arr2, k-1);
}