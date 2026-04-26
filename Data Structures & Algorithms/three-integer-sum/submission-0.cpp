class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0;i<n-2;i++){
            int l = i + 1, r = n-1;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            while(l<r){
                int sum = nums[l] + nums[r] + nums[i];
                if(sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    int curr = nums[l];
                    while(nums[l] == curr && l <= r){
                        l++;
                    }

                    curr = nums[r];
                    while(nums[r] == curr && l <= r){
                        r--;
                    }
                    continue;
                }

                if(sum > 0){
                    r--;
                } else {
                    l ++;
                }
            }
        }

        return res;
    }
};
