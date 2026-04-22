class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;

        // find the l and r of each height
        for(int i = 0;i<n;i++){
            int l = i;
            for(int j = i-1;j>=0;j--){
                if(heights[j] < heights[i]) break;
                l = j;
            }

            int r = i;
            for(int j = i+1;j<n;j++){
                if(heights[j] < heights[i]) break;
                r = j;
            }

            res = max(res, heights[i] * (r-l+1));
        }

        return res;
    }
};
