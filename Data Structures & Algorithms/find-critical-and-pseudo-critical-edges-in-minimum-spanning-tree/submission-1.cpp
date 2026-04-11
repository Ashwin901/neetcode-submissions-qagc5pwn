class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<vector<int>>> aList;
        int m = edges.size();

        for(int i = 0;i<edges.size();i++){
            int n1 = edges[i][0], n2 = edges[i][1], w = edges[i][2];
            aList[n1].push_back({w,n2,i});
            aList[n2].push_back({w,n1,i});
        }

        auto getMSTWeight = [&](int skipEdge, int forceEdge) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
            unordered_set<int> visited;
            int currentRes = 0;

            if (forceEdge != -1) {
                visited.insert(edges[forceEdge][0]);
                visited.insert(edges[forceEdge][1]);
                currentRes += edges[forceEdge][2];
                for (int node : {edges[forceEdge][0], edges[forceEdge][1]}) {
                    for (auto& edge : aList[node]) {
                        if (edge[2] != skipEdge && edge[2] != forceEdge) minHeap.push(edge);
                    }
                }
            } else {
                visited.insert(0);
                for (auto& edge : aList[0]) {
                    if (edge[2] != skipEdge) minHeap.push(edge);
                }
            }

            while (!minHeap.empty()) {
                vector<int> top = minHeap.top(); minHeap.pop();
                int weight = top[0], node = top[1];
                if (visited.count(node)) continue;
                visited.insert(node);
                currentRes += weight;
                for (auto& edge : aList[node]) {
                    if (edge[2] != skipEdge) minHeap.push(edge);
                }
            }
            return (visited.size() == n) ? currentRes : INT_MAX;
        };

        int baseMST = getMSTWeight(-1, -1);
        vector<int> critical, pCritical;

        for (int i = 0; i < m; i++) {
            if (getMSTWeight(i, -1) > baseMST) {
                critical.push_back(i);
            } else if (getMSTWeight(-1, i) == baseMST) {
                pCritical.push_back(i);
            }
        }

        return {critical, pCritical};
    }
};