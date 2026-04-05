class Solution {
public:
    int minDistance(string word1, string word2) {
        int rows = word1.size(),  cols = word2.size();

        vector<vector<int>> dp(rows+1, vector<int> (cols+1,0));

        for(int i = 1;i<=cols;i++){
            dp[0][i] = i;
        }

        for(int i=1;i<=rows;i++){
            dp[i][0] = i;
        }

        for(int i = 1;i<=rows;i++){
            for(int j = 1;j<=cols;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }

        return dp[rows][cols];
    }
};
