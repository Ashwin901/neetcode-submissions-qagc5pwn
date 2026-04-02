class Solution {
public:
    bool isInside(int i, int j, int m, int n){
        if(i >= m || j >= n) return false;
        return true;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));

        return dfs(0,0,m,n,dp);
    }

    int dfs(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ways = 0;
        if(isInside(i+1,j,m,n)) ways += dfs(i+1,j,m,n,dp);
        if(isInside(i,j+1,m,n)) ways += dfs(i,j+1,m,n,dp);
        dp[i][j] = ways;
        return dp[i][j];
    }
};
