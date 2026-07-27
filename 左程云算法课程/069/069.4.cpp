class Solution {
public:
    int p=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        return f(grid,m-1,n-1,k,0);
    }
    //从(0,0)到(i,j)的路径和中被k除 余数为r的路径数目
    long long f(vector<vector<int>>& grid,int i,int j,int k,int r)
    {   if(i==0&&j==0)
      {
        return grid[0][0]%k==r?1:0;
      }
      if(i<0||j<0)
      {
        return 0;
      }
      long long p1=f(grid,i-1,j,k,(100*k+r-grid[i][j])%k);
      long long p2=f(grid,i,j-1,k,(100*k+r-grid[i][j])%k);
      return (p1%p+p2%p)%p;
    }
};
//在做了一定数量的DP问题后，我的确对DP的状态定义有了直觉
//我认为其中很重要的一点在于初始时对可变参数的选择
//因为我们总是采用暴力递归开始的写法，我们就需要考虑f可变参数对递归的印象
//TLE 约80pts 
class Solution {
public:
    int p = 1e9 + 7;
    int dp[50005][51];
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int sum=0;
        for (int j = 0; j < n; j++) {
            sum+=grid[0][j];
            for (int r = 0; r < k; r++) {
                dp[j][r] = sum % k == r ? 1 : 0;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {     
                long long temp[51];//记录dp[i-1][j][r]
                for(int r=0;r<k;r++)
                {
                    temp[r]=dp[j][r];
                }
                for (int r = 0; r < k; r++) {
                    long long p1 = temp[(100 * k + r - grid[i][j]) % k];
                    long long p2 =j - 1 >= 0 ? dp[j - 1][(100 * k + r - grid[i][j]) % k]: 0;
                    long long ans = (p1 % p + p2 % p) % p;
                    dp[j][r] = ans;
                }
            }
        }
        return dp[n - 1][0];
    }
};
// 这里的m、n太大，开三维数组会MLE——我们考虑直接空间压缩版本
// r维的遍历是没有顺序的，因此可能会发生数据污染——到底是ij还是i-1 j
//解决方法是开一个辅助数组来存dp[i-1][j][r] 
