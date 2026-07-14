class Solution {
public:
    const int M=1e9+7;
    int minn=M;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minn=min(minn,matrix[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, f(matrix, i, j));
            }
        }
        return ans;
    }
    // 以(i,j)为终点的最长递增路径，怎么保证从小到大？
    int f(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(matrix[i][j]==minn)
        {
            return 1;
        }
        int ans=1;
        if(i-1>=0&&matrix[i][j]>matrix[i-1][j])
        {
            ans=max(ans,f(matrix,i-1,j)+1);
        }
        if(j-1>=0&&matrix[i][j]>matrix[i][j-1])
        {
            ans=max(ans,f(matrix,i,j-1)+1);
        }
        if(i+1<m&&matrix[i][j]>matrix[i+1][j])
        {
            ans=max(ans,f(matrix,i+1,j)+1);
        }
        if(j+1<n&&matrix[i][j]>matrix[i][j+1])
        {
            ans=max(ans,f(matrix,i,j+1)+1);
        }
        return ans;
    }
};
//这里ans=1的BUG真的很难崩啊
//v1暴力递归版，绝大部分都过了，TLE
 class Solution {
public:
    const int M=1e9+7;
    int minn=M;
    int dp[205][205];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                minn=min(minn,matrix[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, f(matrix, i, j));
            }
        }
        return ans;
    }
    // 以(i,j)为终点的最长递增路径，怎么保证从小到大？
    int f(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(matrix[i][j]==minn)
        {   dp[i][j]=1;
            return 1;
        }
        int ans=1;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i-1>=0&&matrix[i][j]>matrix[i-1][j])
        {
            ans=max(ans,f(matrix,i-1,j)+1);
        }
        if(j-1>=0&&matrix[i][j]>matrix[i][j-1])
        {
            ans=max(ans,f(matrix,i,j-1)+1);
        }
        if(i+1<m&&matrix[i][j]>matrix[i+1][j])
        {
            ans=max(ans,f(matrix,i+1,j)+1);
        }
        if(j+1<n&&matrix[i][j]>matrix[i][j+1])
        {
            ans=max(ans,f(matrix,i,j+1)+1);
        }
        dp[i][j]=ans;
        return ans;
    }
};
//简单改了一个记忆化搜索就过了
//性能20ms/18.28MB
//这里的依赖关系难以整理，所以只到记忆化搜索的版本就截止了 
