class Solution {
public:

    bool isInside(int i, int j, int rows, int cols){
        if(i < 0 || i >= rows || j < 0 || j >= cols){
            return false;
        }

        return true;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols,-1));
        int res = 1;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                res = max(res, dfs(i,j,rows,cols, matrix,dp));
            }
        }

        return res;
    }

    int dfs(int i, int j, int rows, int cols, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        
        if(dp[i][j] != -1) return dp[i][j];
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        int path = 0;
        for(int k = 0;k<4;k++){
            if(isInside(i+dx[k], j+dy[k],rows, cols) && matrix[i][j] < matrix[i+dx[k]][j+dy[k]]){
                path = max(path, dfs(i+dx[k], j+dy[k],rows,cols,matrix,dp));
            }
        }

        dp[i][j] = 1 + path;
        return dp[i][j];
    }
};
