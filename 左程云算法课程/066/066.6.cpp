class Solution {
public:
    int dp[30005];
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        dp[0] = 0;
        if (s[0] == '(' && s[1] == ')') {
            dp[1] = 2;
            ans = 2;
        }
        for (int i = 2; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = dp[i - 2] + 2;
                } else {
                    int len = dp[i - 1];
                    if (i - len - 1 >= 0 && s[i - len - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (i - len - 2 >= 0) {
                            dp[i] += dp[i - len - 2];
                        }

                    } else {
                        dp[i] = 0;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// 理解这个例题需要好的例子,如"(()())())()()()("
// 这里的DP依然是位置依赖的状态定义
// 这个问题有点面向答案编程了
