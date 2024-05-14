class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet Alice = DisjointSet(n), Bob = DisjointSet(n);

        int cnt = 0;
        for (int i=0; i<edges.size(); i++) {
            if (edges[i][0] == 3) {
                cnt += Alice.unionBySize(edges[i][1], edges[i][2], cnt) || Bob.unionBySize(edges[i][1], edges[i][2], cnt);
            }
        }

        for (int i=0; i<edges.size(); i++) {
            if (edges[i][0] == 1) {
                cnt += Alice.unionBySize(edges[i][1], edges[i][2], cnt);
            }
            else if (edges[i][0] == 2)
                cnt += Bob.unionBySize(edges[i][1], edges[i][2], cnt);
        }

        for (int i=2; i<=n; i++) {
            if (Alice.findPar(1) != Alice.findPar(i)) return -1;
            if (Bob.findPar(1) != Bob.findPar(i)) return -1;
        }
        return cnt;
    }
};