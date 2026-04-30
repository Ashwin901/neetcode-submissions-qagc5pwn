class Solution {
public:

    int helper(int idx, int n, vector<int> &nums, int target, int curr){
        if(idx == n) return target == curr ? 1 : 0;

        return helper(idx+1, n,nums,target,curr+nums[idx]) + helper(idx+1,n,nums,target,curr);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(abs(target) > sum) return 0;
        if((sum-target)%2 != 0) return 0;
        target = (sum - target)/2;

        return helper(0,n,nums,target,0);
    }
};
