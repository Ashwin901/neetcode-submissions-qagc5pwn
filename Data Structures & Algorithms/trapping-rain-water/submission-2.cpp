class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> l(n,0);
        int curr = height[0];
        for(int i = 1;i<n-1;i++){
            curr = max(curr, height[i]);
            l[i] = curr;
        }

        curr = height[n-1];
        int res = 0;
        for(int i = n-2;i>0;i--){
            curr = max(curr, height[i]);
            res += (min(l[i], curr) - height[i]);
        }

        return res;
    }
};
