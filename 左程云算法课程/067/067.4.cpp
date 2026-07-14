class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        return f(s,0,n-1);
    }
    //状态定义仍然没想到 ：区间DP f(i,j)即为[i,j]区间的最长回文子序列
    int f(string s,int i,int j)
    {
        if(i==j)
        {return 1;
        }
        if(i==j-1&&s[i]==s[j])
        {
            return 2;
        }
        if(i==j-1&&s[i]!=s[j])
        {
            return 1;
        }
        if(s[i]==s[j])
        {
            return f(s,i+1,j-1)+2;
        }
        else
        {
            return max(f(s,i+1,j),f(s,i,j-1));
        }
    }
};
//v1，暴力递归，MLE了
//这里的状态定义是我抄的，然后转移方程带点臆想成分，论证不是很充分
 class Solution {
public:
    int dp[1005][1005];
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return f(s,0,n-1);
    }
    //状态定义仍然没想到 ：区间DP f(i,j)即为[i,j]区间的最长回文子序列
    int f(string s,int i,int j)
    {   int ans;
        if(i==j)
        {return 1;
        }
        if(i==j-1&&s[i]==s[j])
        {
            return 2;
        }
        if(i==j-1&&s[i]!=s[j])
        {
            return 1;
        }

        if(dp[i][j]!=-1)
        { return dp[i][j];
        }
        if(s[i]==s[j])
        {   
            ans=f(s,i+1,j-1)+2;
        }
        else
        {
            ans=max(f(s,i+1,j),f(s,i,j-1));
        }
        dp[i][j]=ans;
        return ans;
    }
};
//改记忆化搜索全过了，但是仍然MLE

class Solution {
public:
    int dp[1005][1005];
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                int ans;
                if (i == j) {
                    ans = 1;
                } else if (s[i] == s[j]) {
                    ans = dp[i + 1][j - 1] + 2;
                } else {
                    ans = max(dp[i + 1][j], dp[i][j - 1]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
}; 
//神秘常数卡我5分钟！！！
//v3是递推版本，已经通过了
//性能39ms/12.85MB
class Solution {
public:
    int dp[1005];
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            int prev = 0;
            for (int j = i; j < n; j++) {
                int ans;
                int temp;
                if (i == j) {
                    ans = 1;
                } else if (s[i] == s[j]) {
                    ans = prev + 2;
                } else {
                    ans = max(dp[j], dp[j - 1]);
                }
                temp = dp[j];
                dp[j] = ans;
                prev = temp;
            }
        }
        return dp[n - 1];
    }
};
//这里的空间优化和之前的套路完全一样
//性能23ms/9.20MB 
