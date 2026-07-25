//https://leetcode.cn/problems/profitable-schemes/description/
class Solution {
public:
    int p=1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        long long maxProfit=0;
        for(int i=0;i<group.size();i++)
        {
            maxProfit+=profit[i];
        }
        long long ans=0;
        for(int pro=minProfit;pro<=maxProfit;pro++)
        {
            ans=(f(0,n,pro,group,profit)%p+ans%p)%p;
        }
        return ans;
    }
    //f递归函数表示[i,m-1]的工作中产生了p利润，成员不超过g的方案数
    long long f(int i,int g,int p,vector<int>&group,vector<int>&profit)
    { int m=group.size();
      if(i==m)
      {
        return 0;
      }
      if(i==0&&p==0)
      {
        return 1;
      }
      //当前刚好p适配
      if(g>=group[i]&&p==profit[i])
      {
        return 1;
      }
      //讨论第i种工作是否纳入计划,如果不纳入，考虑i+1往后的方案数
      int p1=f(i+1,g,p,group,profit);
      int p2=0;
      if(g>=group[i]&&p>=profit[i])
      { p2=f(i+1,g-group[i],p-profit[i],group,profit);
      }
      return p1+p2;
    }
};
//假设我们理解这个问题为什么要用三维DP来做
//尝试一下，未解决，难道我的思路是走不通的吗？为什么？

class Solution {
public:
    int mod = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {

        return f(0, n, minProfit, group, profit);
    }
    // f递归函数表示[i,m-1]的工作中至少还需要产生p利润，成员不超过g的方案数
    long long f(int i, int g, int p, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        if (g <= 0) {
            return p <= 0 ? 1 : 0;
        }
        if (i == m) {
            return p <= 0 ? 1 : 0;
        }
        // 讨论第i种工作是否纳入计划,如果不纳入，考虑i+1往后的方案数
        int p1 = f(i + 1, g, p, group, profit);
        int p2 = 0;
        if (g >= group[i]) {
            p2 = f(i + 1, g - group[i], p - profit[i], group, profit);
        }
        return (p1%mod + p2%mod)%mod;
    }
};
//改动了状态定义以及basecase的问题之后，这个暴力递归版本就过了
//但仍然TLE 
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[105][105][105];
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return f(0, n, minProfit, group, profit);
    }
    // f递归函数表示[i,m-1]的工作中至少还需要产生p利润，成员不超过g的方案数
    long long f(int i, int g, int p, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        if (g <= 0) {
            return p <= 0 ? 1 : 0;
        }
        if (i == m) {
            return p <= 0 ? 1 : 0;
        }
        if(dp[i][g][p]!=-1)
        {return dp[i][g][p];
        }
        // 讨论第i种工作是否纳入计划,如果不纳入，考虑i+1往后的方案数
        int p1 = f(i + 1, g, p, group, profit);
        int p2 = 0;
        if (g >= group[i]) {
            p2 = f(i + 1, g - group[i], max(0,p - profit[i]), group, profit);
        }
        long long ans=(p1%mod + p2%mod)%mod;
        dp[i][g][p]=ans;
        return ans;
    }
};
//如何避免可变参数到0以下？
//把可能小于零的参数做max(0,s)处理！
//挂dp表的记忆化搜索其实还不太快，但好在已经过了 
