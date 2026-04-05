class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();

        if(n1 + n2 != n3) return false;
        vector<vector<int>> dp(
            n1+1 ,
            vector<int>(n2+1 , -1)
        );
        return dfs(0,0,0,n1,n2,n3,s1,s2,s3,dp);
    }

    bool dfs(int i1, int i2, int i3, int n1, int n2, int n3,
                string s1, string s2, string s3, vector<vector<int>> &dp){

        if(i1 == n1 && i2 == n2) return true;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        bool r1 = false, r2 = false;
        if(i1 < n1 && s1[i1] == s3[i3]){
            r1 = dfs(i1+1,i2,i3+1,n1,n2,n3,s1,s2,s3,dp);
        }

        if(i2 < n2 && s2[i2] == s3[i3]){
            r2 = dfs(i1,i2+1,i3+1,n1,n2,n3,s1,s2,s3,dp);
        }

        return dp[i1][i2] = r1 || r2;
    }
};