class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n): parent(n+1), size(n+1, 1) {
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    void unionBySize(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV) return;
        else if (size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
        return;
    }
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = (row.size()+1)/2;
        DisjointSet ds = DisjointSet(n);
        for (int i=0; i<row.size(); i+=2) {
            if (row[i]/2 != row[i+1]/2) 
                ds.unionBySize(row[i]/2, row[i+1]/2);
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (ds.parent[i] != i) cnt++;
        }
        return cnt;
    }
};