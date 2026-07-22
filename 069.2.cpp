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
//尝试一下，未解决
