class Solution {
public:
    bool isMatch(string s, string p) {
        int rows = s.size();
        int cols = p.size();

        vector<vector<int>> dp(rows+1, vector<int> (cols+1,0));
        dp[rows][cols] = 1;

        for(int i = rows;i>=0;i--){
            for(int j =cols-1;j>=0;j--){
                if(j + 1 < cols && p[j+1] == '*'){
                    if(dp[i][j+2]){
                        dp[i][j] = 1;
                        continue;
                    }
                }
                
                if(i < rows && (p[j] == '.' || s[i] == p[j])){
                    dp[i][j] = dp[i+1][j+1];
                }

                if(p[j] == '*'){
                    dp[i][j] = dp[i][j+1];
                    if(i < rows && j > 0 && (p[j-1] == '.' || p[j-1] == s[i])){
                        dp[i][j] = dp[i][j] || dp[i+1][j];
                    }
                }
            }
        }

        return dp[0][0];
    }
};
