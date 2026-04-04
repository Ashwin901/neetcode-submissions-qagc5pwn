class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;


        for(int i = 0;i<n;i++){
            sum += nums[i];
        }

        if(sum % 2) return false;

        sum = sum / 2;
                
        vector<int> prevRow(sum+1,0);
        prevRow[0] = 1;
        
        for(int i = 1;i<=n;i++){
            vector<int> currRow(sum+1,0);
            currRow[0] = 1;
            for(int j = 1;j<=sum;j++){
                int include = 0;
                if(j >= nums[i-1]){
                    include = prevRow[j-nums[i-1]];
                }
                currRow[j] = include || prevRow[j];
            }
            prevRow = currRow;
        }

        return prevRow[sum];
    }
};
