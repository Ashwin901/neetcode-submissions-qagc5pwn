class Solution {
public:
    int numDistinct(string s, string t) {
        int rows = s.length(), cols = t.length();
        vector<vector<int>> dp(rows+1, vector<int> (cols+1,0));
        for(int i = 0;i<=rows;i++){
            dp[i][cols] =1;
        }

        for(int i = rows-1;i>=0;i--){
            for(int j = cols-1;j>=0;j--){
                dp[i][j] = dp[i+1][j];
                if(s[i] == t[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
        
    }
};
