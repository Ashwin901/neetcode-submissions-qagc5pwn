class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int cMax = 1, cMin = 1;

        for(int i = 0;i<n;i++){
            int num = nums[i];
            int tmp = cMax * num;
            cMax = max(num, max(cMax* num, cMin * num));
            cMin = min(num, min(tmp,cMin*num));

            res = max(res, cMax);
        }

        return res;
    }
};
