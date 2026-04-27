class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        int leftMax = height[0], rightMax = height[n-1];

        int i = 0, j = n-1;

        while(i < j){
            if(leftMax <= rightMax){
                i++;
                leftMax = max(leftMax, height[i]);
                res += leftMax - height[i];
            } else {
                j--;
                rightMax = max(rightMax, height[j]);
                res += rightMax - height[j];
            }
        }

        return res;
    }
};
