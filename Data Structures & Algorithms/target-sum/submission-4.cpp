class Solution {
public:

    int helper(int idx, int n, vector<int> &nums, int target, int curr){
        // if(target == curr) return 1;
        if(idx == n) return target == curr ? 1 : 0;

        return helper(idx+1, n,nums,target,curr+nums[idx]) + helper(idx+1,n,nums,target,curr);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(abs(target) > sum) return 0;
        if((sum-target)%2 != 0) return 0;
        target = (sum - target)/2;

        vector<vector<int>> dp(n+1, vector<int> (target+1,0));
        dp[n][target] = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = target;j>=0;j--){
                dp[i][j] = dp[i+1][j];
                if(j + nums[i] <= target){
                    dp[i][j] += dp[i+1][j+nums[i]];
                }
            }
        }

        return dp[0][0];
    }
};