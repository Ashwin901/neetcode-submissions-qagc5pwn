class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        res[0] = 0, res[1] = 1;
        if(n == 1) return res;

        for(int i = 2;i<=n;i++){
            int curr = i;
            while(curr > 0){
                if(curr & 1 == 1) res[i]++;
                curr = curr >> 1;
            }
        }

        return res;
    }
};
