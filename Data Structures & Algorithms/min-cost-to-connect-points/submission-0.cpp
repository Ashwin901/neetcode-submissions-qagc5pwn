class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, vector<pair<int, int>>> aList;

        // every node has a path to every other node
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                vector<int> p1 = points[i], p2 = points[j];
                int weight = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                aList[i].push_back({weight,j});
                aList[j].push_back({weight,i});
            }
        }

        std::priority_queue<std::pair<int, int>, 
                    std::vector<std::pair<int, int>>, 
                    std::greater<std::pair<int, int>>> minHeap;

        vector<int> visited(n,0);
        // we will start with the first node
        visited[0] = 1;

        // add all edges of 0 to heap
        for(int i = 0;i<aList[0].size();i++){
            minHeap.push(aList[0][i]);
        }

        int res = 0;
        while(!minHeap.empty()){    
            pair<int, int> top = minHeap.top(); minHeap.pop();
            int weight = top.first;
            int node = top.second;
            if(visited[node]) continue;

            res += weight;
            visited[node] = 1;

            for(int i = 0;i<aList[node].size();i++){
                int neighbour = aList[node][i].second;
                if(visited[neighbour]) continue;
                minHeap.push(aList[node][i]);
            }
        }

        return res;
    }
};
