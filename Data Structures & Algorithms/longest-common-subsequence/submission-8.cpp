class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if(m > n) return  longestCommonSubsequence(s2,s1);

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(s1[i] == s2[j]){
                   dp[i+1][j+1] = 1 + dp[i][j]; 
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
                res = max(res, dp[i+1][j+1]);
            }
        }

        return res;
    }
};
