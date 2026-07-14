class Solution {
public:
    const int Max = 9999999;
    // 从左上角(1,1)走到(i,j)的最小路程 grid[0][0]->grid[i-1][j-1]
    int dp[205][205];
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        dp[1][1] = grid[0][0];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i > 1) {
                    dp[i][j] = dp[i - 1][j] + grid[i - 1][j - 1];
                }
                if (j > 1) {
                    if (dp[i][j] == -1) 
                    {dp[i][j] =  dp[i][j - 1] + grid[i - 1][j - 1];
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i - 1][j - 1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
//这个二维递推太经典，我跳过了中间的记忆化搜索尝试就写出了现在的版本

class Solution {
public:
    const int Max = 9999999;
    // 从左上角(1,1)走到(i,j)的最小路程 grid[0][0]->grid[i-1][j-1]
    int dp[205];
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] + grid[0][j - 1];
        }

        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > 1) {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i - 1][j - 1];
                } else {
                    dp[j] = dp[j] + grid[i - 1][j - 1];
                }
            }
        }

        return dp[n];
    }
};
// 从底到顶的DP+空间的优化，这个版本我也很熟了，独立完成 
