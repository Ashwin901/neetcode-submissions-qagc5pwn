class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return dfs(0,target,n,nums);
    }

    int dfs(int i, int target, int n,vector<int> &nums){
        if(i == n){
            return target == 0;
        }

        return dfs(i+1,target+nums[i],n,nums) + dfs(i+1, target-nums[i],n,nums);
    }
};
