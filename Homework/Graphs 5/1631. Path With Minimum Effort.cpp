class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> efforts(n, vector<int> (m, INT_MAX));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0,0}});

        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};
        while (!pq.empty()) {
            auto indices = pq.top().second;
            int effort = pq.top().first;
            pq.pop();
            if (indices.first == n-1 && indices.second == m-1) return effort;

            for (int i=0; i<4; i++) {
                int newRow = indices.first + row[i];
                int newCol = indices.second + col[i];
                if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m ) continue;
                int currEffort = max(effort, abs(heights[indices.first][indices.second]-heights[newRow][newCol]));
                if (currEffort >= efforts[newRow][newCol]) continue;
                efforts[newRow][newCol] = currEffort;
                pq.push({currEffort, {newRow, newCol}});
            }
        }

        return -1;
    }
};