class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int res = 0;

        stack<pair<int, int>> s;

        for(int i = 0;i<n;i++){
            if(s.empty()){
                s.push({heights[i],i});
                continue;
            }

            // basically here this height cannot go any left, so it's breadth will start from i
            if(heights[i] >= s.top().first){
                s.push({heights[i],i});
            } else {
                int idx = -1;
                // but if the current height is less than previous ones
                // we see how far left it can go and that idx and heights[i] to stack
                while(!s.empty() && heights[i] < s.top().first){
                    pair<int, int> top = s.top(); s.pop();
                    // till top.second -1 (right) the top.first height could be used because it's height
                    // was lesser than or equal to all the heights above it
                    int area = (i - top.second) * top.first;
                    res = max(res, area);
                    idx = top.second;
                }

                // idx will be the left of heights[i]
                s.push({heights[i], idx});
            }
        }

        while(!s.empty()){
            pair<int, int> top = s.top(); s.pop();
            int area = (n - top.second) * top.first;
            res = max(res, area);
        }

        return res;
    }
};
