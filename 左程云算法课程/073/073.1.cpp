//https://www.luogu.com.cn/problem/P1048
#include <bits/stdc++.h>
using namespace std;
int t,m;
int ti;
int mi;
int dp[1001];//dp[j]表示迄今为止的草药中j时间能获取的最大价值 
int main()
{ cin>>t>>m;
  for(int i=1;i<=m;i++)
  { cin>>ti>>mi;
    for(int j=t;j>=0;j--)
    { dp[j]=max(dp[j],j>=ti?dp[j-ti]+mi:0);
	}
  }
  cout<<dp[t];
  return 0;
}
