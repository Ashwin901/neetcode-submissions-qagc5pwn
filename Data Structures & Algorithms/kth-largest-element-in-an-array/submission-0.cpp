class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int n = nums.size();
        if(n < k) return -1;

        for(int i = 0;i<n;i++){
            if(minHeap.size() < k){
                minHeap.push(nums[i]);
                continue;
            }

            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};
