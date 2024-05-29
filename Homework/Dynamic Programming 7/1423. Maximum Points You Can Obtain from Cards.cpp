class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum = 0;

        int currSum = 0;
        for (int i=0; i<k; i++) {
            currSum += cardPoints[i];
        }
        maxSum = currSum;
        int j = cardPoints.size()-1;
        for (int i=k-1; i>=0; i--) {
            currSum -= cardPoints[i];
            currSum += cardPoints[j--];
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};