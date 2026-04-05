class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> passDays(3,0);
        passDays[0] = 1, passDays[1] = 7, passDays[2] = 30;

        int lastDay = days[n-1];
        vector<int> dp(lastDay+1,INT_MAX);

        unordered_map<int, int> umap;
        for(int i = 0;i<n;i++){
            umap[days[i]] = 1;
        }
        
        dp[lastDay] = min(costs[0], min(costs[1], costs[2])); // no point in taking 7 day or 30 day pass on last day, so if it was the oy day one day pass is the best option
        for(int i = lastDay-1;i>=1;i--){
            if(umap.find(i) == umap.end()){
                // this day need not be included
                dp[i] = dp[i+1];
                continue;
            }

            for(int j=0;j<3;j++){
                int cost = costs[j];
                if(i + passDays[j]-1 < lastDay){
                    cost += dp[i+passDays[j]];
                }
                dp[i] = min(dp[i], cost);
            }
        }

        return dp[1];
    }
};