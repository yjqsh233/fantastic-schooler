class Solution {
public:
    int zero_num=0;int one_num=0;
    void calculate(vector<string>& strs,int i)
    {
        int temp0=0,temp1=0;
        for(int j=0;j<strs[i].size();j++)
        { if(strs[i][j]=='0')
         {
            temp0++;
         }
         else
         {
            temp1++;
         }
        }
        zero_num=temp0;
        one_num=temp1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return f(strs,0,m,n);
    }
    //函数返回值表示strs[i...]的最大子集长度
    int f(vector<string>&strs,int i ,int z,int o)
    { int n=strs.size();
      //basecase
      if(i==n)
      { return 0;
      }
      //尝试策略是考虑当前“末尾”，如果使用则考虑是否超过z、o；如果不使用则考虑后续i+1
      int p1=f(strs,i+1,z,o);
      int p2=0;
      calculate(strs,i);
      if(zero_num<=z&&one_num<=o)
      {
        p2=f(strs,i+1,z-zero_num,o-one_num)+1;
      }
      return max(p1,p2);
    }
};
//问题仍然出现在设计递归函数的可变参数/DP的状态上
//一开始，我完全没有思路该怎么入手这个问题，以及最重要的是“为什么要走DP这条路”？
//TLE
class Solution {
public:
    int zero_num=0;int one_num=0;
    int dp[606][101][101];
    void calculate(vector<string>& strs,int i)
    {
        int temp0=0,temp1=0;
        for(int j=0;j<strs[i].size();j++)
        { if(strs[i][j]=='0')
         {
            temp0++;
         }
         else
         {
            temp1++;
         }
        }
        zero_num=temp0;
        one_num=temp1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(strs,0,m,n);
    }
    //函数返回值表示strs[i...]的最大子集长度
    int f(vector<string>&strs,int i ,int z,int o)
    { int n=strs.size();
      //basecase
      if(i==n)
      { return 0;
      }
      if(dp[i][z][o]!=-1)
      {
        return dp[i][z][o];
      }
      int p1=f(strs,i+1,z,o);
      int p2=0;
      calculate(strs,i);
      if(zero_num<=z&&one_num<=o)
      {
        p2=f(strs,i+1,z-zero_num,o-one_num)+1;
      }
      int ans=max(p1,p2);
      dp[i][z][o]=ans;
      return ans;
    }
};
//挂DP表的记忆化搜索版本，直接过了，很慢
class Solution {
public:
    int zero_num = 0;
    int one_num = 0;
    int dp[606][101][101];
    void calculate(vector<string>& strs, int i) {
        int temp0 = 0, temp1 = 0;
        for (int j = 0; j < strs[i].size(); j++) {
            if (strs[i][j] == '0') {
                temp0++;
            } else {
                temp1++;
            }
        }
        zero_num = temp0;
        one_num = temp1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        // basecase
        //记得删掉memset给dp的初始化-1
        for (int i = len - 1; i >= 0; i--) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    int p1 = dp[i + 1][j][k];
                    int p2 = 0;
                    calculate(strs, i);
                    if (zero_num <= j && one_num <= k) {
                        p2 = dp[i + 1][j - zero_num][k - one_num] + 1;
                    }
                    dp[i][j][k] = max(p1, p2);
                }
            }
        }
        return dp[0][m][n];
    }
};
//从底到顶的递推版本，过了，还是很慢 
class Solution {
public:
    int zero_num = 0;
    int one_num = 0;
    int dp[101][101];
    void calculate(vector<string>& strs, int i) {
        int temp0 = 0, temp1 = 0;
        for (int j = 0; j < strs[i].size(); j++) {
            if (strs[i][j] == '0') {
                temp0++;
            } else {
                temp1++;
            }
        }
        zero_num = temp0;
        one_num = temp1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        // basecase
        //记得删掉memset给dp的初始化-1
        for (int i = len - 1; i >= 0; i--) { 
            calculate(strs, i);
            for (int j = m; j>=0; j--) {
                for (int k =n; k >=0; k--) {
                    int p1 = dp[j][k];
                    int p2 = 0;
                    if (zero_num <= j && one_num <= k) {
                        p2 = dp[j - zero_num][k - one_num] + 1;
                    }
                    dp[j][k] = max(p1, p2);
                }
            }
        }
        return dp[m][n];
    }
};
//做了cal函数调用的小优化 75ms 
//关键是为什么这里的遍历方向必须是从大到小
//性能上，时间179ms（慢）/11.91MB 
class Solution {
public:
    int zero_num = 0;
    int one_num = 0;
    int dp[101][101];
    void calculate(vector<string>& strs, int i) {
        int temp0 = 0, temp1 = 0;
        for (int j = 0; j < strs[i].size(); j++) {
            if (strs[i][j] == '0') {
                temp0++;
            } else {
                temp1++;
            }
        }
        zero_num = temp0;
        one_num = temp1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        // basecase
        // 记得删掉memset给dp的初始化-1
        for (int i = len - 1; i >= 0; i--) {
            calculate(strs, i);
            for (int j = m; j >= zero_num; j--) {
                for (int k = n; k >= one_num; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zero_num][k - one_num] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// j,k下限优化
// 如果不满足条件就没有改动的必要了！避免了无效的计算
//43ms/11.84MB，最优解 
