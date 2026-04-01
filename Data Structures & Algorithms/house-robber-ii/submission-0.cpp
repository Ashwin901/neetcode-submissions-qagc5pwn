class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);

        int res = -1;

        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // run from 0 to n-1
        for(int i = 2;i<n-1;i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        res = dp[n-2];
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);

        // run from 1 to n
        for(int i = 3;i<n;i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        res = max(res, dp[n-1]);

        return res;
    }
};
