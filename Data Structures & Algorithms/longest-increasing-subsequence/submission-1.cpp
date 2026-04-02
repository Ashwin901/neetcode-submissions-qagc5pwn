class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<vector<int>> dp(n, vector<int> (n+1,-1));
         return dfs(0,n,-1,nums, dp);
    }
    
    int dfs(int i, int n,int prevIdx, vector<int> &nums, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];

        int withoutNum = dfs(i+1,n,prevIdx,nums,dp);
        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            dp[i][prevIdx+1] = max(1+dfs(i+1,n,i,nums,dp), withoutNum);
        } else {
            dp[i][prevIdx+1] = withoutNum;
        }

        return dp[i][prevIdx+1];
    }
};
