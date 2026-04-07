class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p.length();
        vector<vector<int>> dp(l1+1, vector<int> (l2,-1));
        return dfs(0,0,l1,l2,s,p,dp);
    }

    bool dfs(int i, int j, int l1, int l2, string s, string p,vector<vector<int>> &dp){
        if(j == l2) return i == l1;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 0;
        // skip if j + 1 = '*'
        if(j + 1 < l2 && p[j+1] == '*'){
          if(dfs(i,j+2,l1,l2,s,p,dp)) 
            {
                dp[i][j] = 1;
                return true;  
            }
        }

        // match
        if(i < l1 && (p[j] == '.' || s[i] == p[j])){
            dp[i][j] =  dfs(i+1,j+1,l1,l2,s,p,dp);
        }

        // p[j] = '*'
        // 1. skip
        if(p[j] == '*'){
            if(dfs(i,j+1,l1,l2,s,p,dp)) {
                dp[i][j] = 1;
                return true;
            }
            if(i < l1 && j > 0 && (p[j-1] == '.' || p[j-1] == s[i])) 
            {
                dp[i][j] = dfs(i+1,j,l1,l2,s,p,dp);
            } 
        }
        
        return dp[i][j];
    }
};
