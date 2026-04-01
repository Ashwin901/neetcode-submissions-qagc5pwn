class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        sort(coins.begin(), coins.end());

        vector<int> dp(amount+1,-1);
        dp[0] = 0;

        for(int i = 1;i<=amount;i++){
            for(int j = 0;j<coins.size();j++){
                if(i >= coins[j] && dp[i - coins[j]] >= 0){
                    if(dp[i] == -1){
                        dp[i] = 1 + dp[i-coins[j]];
                    } else {
                        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                    }
                }
            }
        }

        return dp[amount];
    }
};
