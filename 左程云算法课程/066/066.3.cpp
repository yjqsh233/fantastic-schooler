class Solution {
public:
    int dp[105];
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        dp[0] = 1;
        if (s[0] == '0') {
            dp[1] = 0;
        } else {
            dp[1] = 1;
        }
        for (int i = 2; i <= n; i++) 
        {
            int ans = 0;
            if (s[i - 1] != '0') {
                ans += dp[i-1];
            }
            if (s[i - 2] == '1') {
                ans += dp[i-2];
            } else if (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6') {
                ans += dp[i-2];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
//有了066.2例题的铺垫，现在我考虑DP的问题已经有了比较系统的方法论
//这个问题从v1到v3都是我独立完成
