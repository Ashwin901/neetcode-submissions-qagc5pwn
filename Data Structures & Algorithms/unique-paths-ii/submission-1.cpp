class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;


        vector<int> prevRow(n,0);
        for(int i = m-1;i>=0;i--){
            vector<int> currRow(n,0);
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 1) {
                    currRow[j] = 0;
                } else if(i == m-1 && j == n-1) {
                    currRow[j] = 1;
                } else {
                    currRow[j] = prevRow[j] + (j + 1 < n ? currRow[j+1] : 0);
                }
            }
            prevRow = currRow;
        }

        return prevRow[0];
    }
};