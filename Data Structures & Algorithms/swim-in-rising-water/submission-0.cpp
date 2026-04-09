class Solution {
public:

    bool isInside(int i, int j, int rows, int cols){
        if(i < 0 || j < 0 || i >= rows || j >= cols) return false;

        return true;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        unordered_map<string,vector<vector<int>>> aList;

        // build the edges along with their weights
        // for(int i = 0;i<rows;i++){
        //     for(int j = 0;j<cols;j++){
        //         int sourceKey = to_string(i) + "," + to_string(j);
        //         vector<pair<int>> edges = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        //         for(int k = 0;k<4;k++){
        //             int x = i + edges[k].first, y = j + edges[k].second;
        //             int destKey = to_string(x) + "," + to_string(y);
        //             if(isInside(x,y, rows, cols)){
        //                 aList[sourceKey].push_back({grid[x][y], max(grid[i][j], grid[x][y])});
        //             }
        //         }
        //     }
        // }

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        // {time,x,y}
        minHeap.push({0,0,0});

        vector<vector<int>> time(rows, vector<int> (cols,-1));
        int maxTime = -1;
        while(!minHeap.empty()){
            vector<int> top = minHeap.top(); minHeap.pop();
            int currTime = top[0], i = top[1], j = top[2];
            if(time[i][j] != -1) continue;

            time[i][j]= currTime;
            maxTime = max(maxTime,currTime);
            if(i == rows -1 && j == cols-1){
                return maxTime;
            }

            // scan all edges of i,j and add it to minHeap
            vector<pair<int,int>> edges = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            for(int k = 0;k<4;k++){
                int x = i + edges[k].first, y = j + edges[k].second;
                if(isInside(x,y, rows, cols) && time[x][y] == -1){
                    int weight = max(grid[i][j], grid[x][y]);
                    minHeap.push({ weight, x,y});
                }
            }
        }

        return -1;
    }
};
