class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[m-1][n-1] = 1;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 1) continue;
                if(i + 1 < m){
                    dp[i][j] += dp[i+1][j];
                }

                if(j+1 < n){
                    dp[i][j] += dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};