class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n,0));
        int res = 0;
        for(int len=1;len<=n;len++){
            for(int i = 0;i<n-len+1;i++){
                int j = i + len - 1;
                if(s[i] == s[j] && (len <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }

        return res;
    }
};
