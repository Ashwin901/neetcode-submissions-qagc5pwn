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

            if(heights[i] >= s.top().first){
                s.push({heights[i],i});
            } else {
                int idx = -1;
                while(!s.empty() && heights[i] < s.top().first){
                    pair<int, int> top = s.top(); s.pop();
                    int area = (i - top.second) * top.first;
                    res = max(res, area);
                    idx = top.second;
                }

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
