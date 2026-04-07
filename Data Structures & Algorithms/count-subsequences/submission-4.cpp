class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n2 > n1) return 0;

        vector<vector<int>> dp(s.length(), vector<int> (t.length(),-1));
        return helper(0,0,s,t,dp);
    }

    int helper(int idx, int j, string s, string t, vector<vector<int>> &dp){
        if(j == t.length()){
            return 1;
        }

        if(idx >= s.length()) return 0;

        if(dp[idx][j] != -1) return dp[idx][j];
        
        dp[idx][j] = helper(idx+1,j,s,t,dp);
        if(s[idx] == t[j]){
            dp[idx][j] += helper(idx+1,j+1,s,t,dp);
        }

        return dp[idx][j];
    }
};
