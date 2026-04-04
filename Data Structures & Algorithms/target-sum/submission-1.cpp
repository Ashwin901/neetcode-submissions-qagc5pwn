class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> dp;
        return dfs(0,target,n,nums,dp);
    }

    int dfs(int i, int target, int n,vector<int> &nums, unordered_map<string, int> & dp){
        if(i == n){
            return target == 0;
        }

        string key = to_string(i) + "," + to_string(target);
        if(dp.find(key) != dp.end()) return dp[key];


        dp[key] =  dfs(i+1,target+nums[i],n,nums,dp) + dfs(i+1, target-nums[i],n,nums,dp);

        return dp[key];
        }
};
