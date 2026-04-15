class Solution {
public:

    int findParent(int node, unordered_map<int, int> &parent){
        while(parent[node] != node){
            node = parent[node];
        }

        return node;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // number of nodes

        unordered_map<int, int> parent;
        unordered_map<int, int> rank;

        for(int i= 0;i<n;i++){
            parent[i+1] = i+1;
            rank[i+1] = 0;
        }

        for(int i = 0;i<edges.size();i++){
            int p1 = findParent(edges[i][0], parent);
            int p2 = findParent(edges[i][1], parent);

            if(p1 == p2) return edges[i];

            parent[p2] = p1;
        }

        return {};
    }
};
