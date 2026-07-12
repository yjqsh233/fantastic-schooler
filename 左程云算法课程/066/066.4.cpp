//https://leetcode.cn/problems/decode-ways-ii/
class Solution {
public:
    const int p = 1e9 + 7;
    long long dp[100005];
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        dp[0] = 1;
        if (s[0] == '0') {
            dp[1] = 0;
        } else if (s[0] == '*') {
            dp[1] = 9;
        } else {
            dp[1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            long long ans = 0;
            if (s[i - 1] != '0') {
                if (s[i - 1] == '*') {
                    ans = (ans % p + (9 % p * dp[i - 1] % p) % p) % p;
                } else {
                    ans = (ans % p + dp[i - 1] % p) % p;
                }
            }
            if (s[i - 2] == '1') {
                if (s[i - 1] != '*') {
                    ans = (ans % p + dp[i - 2] % p) % p;
                } else {
                    ans = (ans % p + 9 * dp[i - 2] % p) % p;
                }
            } else if (s[i - 2] == '2') {
                if (s[i - 1] >= '0' && s[i - 1] <= '6') {
                    ans = (ans % p + dp[i - 2] % p) % p;
                }
                if (s[i - 1] == '*') {
                    ans = (ans % p + 6 * dp[i - 2] % p) % p; //
                }
            } else if (s[i - 2] == '*') {
                if (s[i - 1] >= '0' && s[i - 1] <= '6') {
                    ans = (ans % p + 2 * dp[i - 2] % p) % p;
                } else if (s[i - 1] >= '7' && s[i - 1] <= '9') {
                    ans = (ans % p + dp[i - 2] % p) % p;
                } else {
                    ans = (ans % p + 15 * dp[i - 2] % p) % p; //
                }
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};
// 这里的时间复杂度应该还不是最优
// 从递归入手解决一维DP对我而言已经是非常纯熟的一条思路了
