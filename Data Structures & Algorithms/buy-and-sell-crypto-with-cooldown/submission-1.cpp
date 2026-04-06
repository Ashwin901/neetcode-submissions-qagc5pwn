class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return dfs(0,n,prices, 1, dp);
    }

    int dfs(int i, int n, vector<int> &prices, int buy,vector<vector<int>> &dp){
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int res = INT_MIN;
        if(buy){
            // two options
            // buy
            res = max(res, dfs(i+1,n,prices, 0,dp) - prices[i]);
            // don't buy
            res = max(res,dfs(i+1,n,prices,1,dp));
        }

        if(!buy){
            // two options
            // sell - then you cannot buy on the next day - i + 2
            res = max(res, prices[i] + dfs(i+2,n,prices, 1,dp));
            // hold or don't sell
            res = max(res, dfs(i+1,n,prices, 0,dp));
        }

        dp[i][buy] = res;
        return res;
    }
};
