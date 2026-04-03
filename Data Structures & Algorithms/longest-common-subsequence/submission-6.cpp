class Solution {
public:
int res = 0;
    int longestCommonSubsequence(string s1, string s2) {
        if(s1.length() > s2.length()) return longestCommonSubsequence(s2,s1);
        vector<vector<int>> dp(s1.length(), vector<int> (s2.length(),-1));
        dfs(0,0,s1,s2, dp);
        return res;
    }

    int dfs(int id1, int id2, string s1, string s2, vector<vector<int>> &dp){
        if(id1 == s1.length() || id2 == s2.length()){
            return 0;
        }

        if(dp[id1][id2] != -1) return dp[id1][id2];

        if(s1[id1] == s2[id2]){
            dp[id1][id2] = 1 + dfs(id1+1,id2+1,s1,s2,dp);
        }else {
            dp[id1][id2] = max(dfs(id1+1, id2,s1,s2,dp),
                                dfs(id1,id2+1,s1,s2,dp));
        }

        res = max(res, dp[id1][id2]);
        return dp[id1][id2];
    }
};
