class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int nEdges = times.size();
        
        // build the adjacency list
        unordered_map<int, vector<vector<int>>> aList;

        for(int i = 0;i<nEdges;i++){
            aList[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // minHeap - to keep track of the current shortest distance
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        // push the starting node with 0 cost
        minHeap.push({0,k});

        // keeps track of all the times
        vector<int> cost(n,-1);
        
        // every time cost array is updated we set the value of res, since we are going in the increasing order
        // the last value set will be our answer
        int res = 0;

        // using this just to avoid scanning cost again to see if something was missed
        int visited = 0;

        while(!minHeap.empty()){
            vector<int> top = minHeap.top(); minHeap.pop();
            if(cost[top[1] - 1] != -1) continue;
            
            cost[top[1]-1] = top[0];
            res = top[0];
            visited++;
            
            for(auto it : aList[top[1]]){
                minHeap.push({top[0] + it[1], it[0]});
            }
        }

        if(visited != n) return -1;
        return res;
    }
};
