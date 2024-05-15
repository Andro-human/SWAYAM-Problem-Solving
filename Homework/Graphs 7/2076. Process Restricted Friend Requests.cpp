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
    }
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisjointSet ds = DisjointSet(n);
        vector<bool> res(requests.size());
        for (int i=0; i<requests.size(); i++) {
            vector<int> tempPar = ds.parent, tempSize = ds.size;
            ds.unionBySize(requests[i][0], requests[i][1]);

            bool flag = true;
            for (int j=0; j<restrictions.size(); j++) {
                if (ds.findPar(restrictions[j][0]) == ds.findPar(restrictions[j][1])) {
                    ds.parent = tempPar;
                    ds.size = tempSize;
                    flag = false;
                    break;
                }   
            }
            if (flag) res[i] = true;
            else res[i] = false;
        }

        return res;

    }
};