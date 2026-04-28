class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;
            vector<int> res;
            for(int i =0;i<n;i++){
                // remove all the elements outside of the window
                while(!dq.empty() && dq.front().second <= i-k){
                    dq.pop_front();
                }

                // remove all smaller elements than the current element
                while(!dq.empty() && dq.back().first <= nums[i]){
                    dq.pop_back();
                }

                dq.push_back({nums[i],i});

                if(i >= k-1){
                    res.push_back(dq.front().first);
                }
            }

            return res;
    }
};
