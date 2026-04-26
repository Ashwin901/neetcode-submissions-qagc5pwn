class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r= n-1;
        int res = nums[0];
        while(l <= r){
            // check if l-r is a rotated part or a sorted part
            // if sorted no point in continuing
            if(nums[l] <= nums[r]){
                res = min(res, nums[l]);
                break;
            }
            // now we are definetely in the rotated part
            int mid = l + (r-l)/2;
            res = min(res, nums[mid]);
            if(nums[mid] >= nums[l]){
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }

        return res;
    }
};
