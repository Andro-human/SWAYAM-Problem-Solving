class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n): parent(n+1), size(n+1, 1) {
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    bool unionBySize(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV) {
            return true;
        };
        
        parent[parV] = parU;
        size[parU] += size[parV];
        return false;
    }
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
};


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds = DisjointSet(n);

        vector<int> parent(n+1, -1);
        int firstBad = -1, secondBad = -1;
        for(int i=0; i<n; i++) {
            if (parent[edges[i][1]] != -1) {
                firstBad = i;
                secondBad = parent[edges[i][1]];
            }
            else {
                parent[edges[i][1]] = i;
            }

        }

        // int res1 = 0, res2 = 0;
        for (int i=0; i<n; i++) {
            if (i == firstBad) continue;
            if (ds.unionBySize(edges[i][0], edges[i][1])) {
                if (firstBad == -1) return {edges[i][0], edges[i][1]};
                else return {edges[secondBad][0], edges[secondBad][1]};
            }
            // if (res1 != 0) return {res1, res2};
        }

        return {edges[firstBad][0], edges[secondBad][1]};
    }
};