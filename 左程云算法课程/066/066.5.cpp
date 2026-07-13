class Solution {
public:
    std::stack<char>str;
    int longestValidParentheses(string s) {
    int n=s.size();int len=0;
    for(int i=0;i<n;i++)
    { if(str.empty())
     {  if(s[i]=='(')
      {
        str.push(s[i]);
      }
     }
     else if((str.top()=='(')&&(s[i]=='('))
     {
        str.push(s[i]);
     }
     else if(str.top()=='('&&s[i]==')')
     {  
        len+=2;
        str.pop();
     }
     else
     { len=0;
     }

    }
    return len;
    }
};
//括号匹配问题，考虑用栈来匹配,但这个不连续，操作效果不好，WA
 class Solution {
public:
    int dp[1700];
    int nthUglyNumber(int n) {
        dp[1] = 1;
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(min(dp[i2] * 2, dp[i3] * 3), dp[i5] * 5);
            if (dp[i] == dp[i2] * 2) {
                i2++;
            }
            if (dp[i] == dp[i3] * 3) {
                i3++;
            }
            if (dp[i] == dp[i5] * 5) {
                i5++;
            }
        }
        return dp[n];
    }
};//关键的是这两件事
//1.后面的丑数一定是前面的丑数x2/x3/x5得到的，此即“重叠子结构”和
//2.我们利用三个指针对应丑数，每次把最小乘积对应的下标指针+1
 
