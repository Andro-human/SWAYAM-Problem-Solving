class Disjoint {
    vector<int> rank;
    vector<int> parent;
public: 
    Disjoint(int n): rank(n+1, 1), parent(n+1) {
        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    void UnionOfNodes(int u, int v, int &res1, int &res2) {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV) {
            res1 = u;
            res2 = v;
            return;
        }
        
        else if (rank[parU] < rank[parV]) {
            parent[parU] = parV;
        }
        
        else if (rank[parV] < rank[parU]) {
            parent[parV] = parU;
        }
        else {
            parent[parV] = parU;
            rank[parU]++;
        }
    }
    
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint u1 = Disjoint(n);

        int res1 = 0, res2 = 0;
        for (int i=0; i<n; i++) {
            u1.UnionOfNodes(edges[i][0], edges[i][1], res1, res2);
            if (res1 != 0) return {res1, res2};
        }

        return {};
    }
};