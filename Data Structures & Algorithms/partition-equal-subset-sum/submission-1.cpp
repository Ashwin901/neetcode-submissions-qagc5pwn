class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for(int i = 0;i<n;i++){
            sum += nums[i];
        }

        if(sum % 2 != 0 ) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int> (target+1,-1));

        return dfs(0,target,n,nums,dp);
    }

    bool dfs(int i, int target, int n, vector<int> &nums, vector<vector<int>> &dp){

        if(i == n){
            return target == 0;
        }
        if(target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        dp[i][target] = dfs(i+1, target,n,nums, dp) || dfs(i+1,target -nums[i],n,nums, dp);

        return dp[i][target];
    }
};
