class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));
        
        for (int i=0; i<n; i++) {
            distance[i][i] = 0;
        }
        for (int i=0; i<edges.size(); i++) {
            distance[edges[i][0]][edges[i][1]] = edges[i][2];
            distance[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX) continue;
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }
            }
        } 

        int minCities = INT_MAX;
        int minIdx = -1;
        for(int i=0; i<n; i++) {
            int numCities = 0;
            for (int j=0; j<n; j++) {
                if (distance[i][j] == INT_MAX || distance[i][j] > thres || i==j) 
                    continue;
                
                numCities++;
            }
            cout << numCities << endl;
            if (numCities <= minCities) {
                minCities = numCities;
                minIdx = i;
            }
        }

        return minIdx;
    }
};