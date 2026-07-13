class Solution {
public:
    int dp[27];
    int findSubstringInWraproundString(string s)
    { int n=s.size();
      int len=1;
      int ans=0;
      dp[s[0]-'a']=1;
      for(int i=1;i<n;i++)
      { if((s[i]==s[i-1]+1)||(s[i]=='a'&&s[i-1]=='z'))
       {
        len++;
       }
       else
       {len=1;
       }
       dp[s[i]-'a']=max(dp[s[i]-'a'],len);
      }
      for(int i=0;i<26;i++)
      {ans+=dp[i];
      }
      return ans;
    }
};
//老实说这里的状态定义还很有研究价值，我还不能很好的解释这类问题
