class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int> (2,0));
        // on the last day the only profitable thing to do is sell
        dp[n-1][0] = prices[n-1]; // doing this to handle edge cases (out of bound - i+2)

        for(int i = n-2;i>=0;i--){
            dp[i][0] = max(prices[i]+dp[i+2][1], dp[i+1][0]);
            dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
        }

        return dp[0][1];
    }
};
