class Solution {
public:

    int findParent(int node, unordered_map<int, int> &parent){
        while(parent[node] != node){
            parent[node] = parent[parent[node]];
            node = parent[parent[node]];
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

            if(rank[p1] >= rank[p2]){
                parent[p2] = p1;
                if(rank[p1] == rank[p2]) rank[p1] += 1;
            } else if(rank[p2] > rank[p1]){
                parent[p1] = p2;
            }
            
        }

        return {};
    }
};
