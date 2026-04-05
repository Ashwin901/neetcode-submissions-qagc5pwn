class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> passDays(3);
        passDays[0] = 0, passDays[1] = 6, passDays[2] = 29;
        vector<vector<int>> dp(n,vector<int> (400,-1));
        return dfs(0,n,days,costs,passDays,0,dp);
    }

    int dfs(int i, int n,vector<int> &days, vector<int> &costs,vector<int>&passDays, int tillDay,
    vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][tillDay] != -1) return dp[i][tillDay];

        if(days[i] <= tillDay){
            return dfs(i+1,n,days,costs,passDays,tillDay,dp);
        }

        int res = INT_MAX;

        for(int j = 0;j<3;j++){
            res = min(res, costs[j] + dfs(i+1,n,days,costs,passDays,days[i]+passDays[j],dp));
        }

        dp[i][tillDay] = res;
        return res;
    }
};