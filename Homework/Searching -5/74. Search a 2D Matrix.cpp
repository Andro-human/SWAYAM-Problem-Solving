class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int l = 0, h = m*n-1;

        while (l <= h) {
            int mid = l + (h-l)/2;

            int midCol = mid/n;
            int midRow = mid%n;

            if (matrix[midCol][midRow] == target) {
                return true;
            }
            else if (matrix[midCol][midRow] < target)
                l = mid+1;
            else 
                h = mid-1;
        }

        return false;
    }
};