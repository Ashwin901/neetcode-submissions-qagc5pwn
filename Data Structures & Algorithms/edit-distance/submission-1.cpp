class Solution {
public:

    int helper(int i1, int i2, string s1, string s2, vector<vector<int>> &dp){
        if(i1 == s1.length() && i2 == s2.length()) return 0;
        if(i1 == s1.length()) return s2.length() - i2; // insert the remaining characters of s2
        if(i2 == s2.length()) return s1.length() - i1; // delete the remaining characters of s1

        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1] == s2[i2]) return helper(i1+1, i2+1,s1,s2,dp);
        // replace 
        int repl = 1 + helper(i1+1,i2+1,s1,s2,dp);
        // insert
        int insrt = 1 + helper(i1, i2+1,s1,s2,dp);
        //delete
        int del = 1 + helper(i1+1,i2,s1,s2,dp);

        dp[i1][i2] = min(repl, min(del, insrt));
        return dp[i1][i2];
    }
    int minDistance(string s1, string s2) {
        
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));
        dp[n1][n2] = 0;

        // insertion of remaining characters of s2
        for(int i = 0;i<n2;i++){
            dp[n1][i] = n2-i;
        }

        // deletion of remaining characters of s1
        for(int i = 0;i<n1;i++){
            dp[i][n2] = n1 - i;
        }

        for(int i = n1-1;i>=0;i--){
            for(int j = n2-1;j>=0;j--){
                if(s1[i] == s2[j]) dp[i][j] = dp[i+1][j+1];
                else{
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                }
            }
        }

        return dp[0][0];
    }
};