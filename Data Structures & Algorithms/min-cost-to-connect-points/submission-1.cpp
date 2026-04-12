class UnionFind {
public:
    vector<int> par, rank;

    UnionFind(int n) : par(n), rank(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        if (v != par[v]) {
            par[v] = find(par[v]);
        }
        return par[v];
    }

    bool unionSets(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Using kruskal
        vector<vector<int>> edges;
        // every node has a path to every other node
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                vector<int> p1 = points[i], p2 = points[j];
                int weight = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                edges.push_back({weight,i,j});
            }
        }

        sort(edges.begin(), edges.end());

        UnionFind unf(n);

        int selectedEdges = 0;
        int i = 0, m = edges.size();
        int cost = 0;
        while(i < m && selectedEdges < n-1){
            vector<int> edge = edges[i];
            i++;
            int n1 = edge[1], n2 = edge[2];

            if(!unf.unionSets(n1,n2)) continue; // this edge cannot be picked as n1,n2 belong to the same component

            selectedEdges++;
            cost += edge[0];
        }

        return cost;
    }
};
