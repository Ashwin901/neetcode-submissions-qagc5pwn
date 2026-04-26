class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() -1;
        int leftMax = height[0], rightMax = height[r];

        int res = 0;
        while(l < r){
            // in this case no matter whats on the right we are restricted by the left height
            // so we calculate using the left height and move on
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax, height[l]);
                res += (leftMax - height[l]);
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += (rightMax - height[r]);
            }
        }

        return res;
    }
};
