//https://leetcode.cn/problems/russian-doll-envelopes/
class Solution {
public:
    int dp[100005][2]; // dp[i][0],dp[i][1]表示嵌套个数为i的结尾信封最小
    // 排序能解决吗？
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        dp[1][0] = envelopes[0][0];
        dp[1][1] = envelopes[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (envelopes[i][0] > dp[ans][0] && envelopes[i][1] > dp[ans][1]) {
                ans++;
                dp[ans][0] = envelopes[i][0];
                dp[ans][1] = envelopes[i][1];
            } else if (envelopes[i][0] < dp[1][0] &&
                       envelopes[i][0] < dp[1][1]) {
                ans++;
                // moveforward();
                dp[1][0] = envelopes[i][0];
                dp[1][1] = envelopes[i][1];
            } else {
                int l0 = 0;
                int r0 = ans + 1;
                while (l0 + 1 != r0) {
                    int m0 = l0 + (r0 - l0) / 2;
                    if (dp[m0][0] >= envelopes[i][0]) {
                        r0 = m0;
                    } else {
                        l0 = m0;
                    }
                }
                int l1 = 0;
                int r1 = ans + 1;
                while (l1 + 1 != r1) {
                    int m1 = l1 + (r1 - l1) / 2;
                    if (dp[m1][1] >= envelopes[i][1]) {
                        r1 = m1;
                    } else {
                        l1 = m1;
                    }
                }
                int r = max(r0, r1);
                dp[r][0] = envelopes[i][0];
                dp[r][1] = envelopes[i][1];
            }
        }
        return ans;
    }
};
// 模仿072.1O(nlogn)解法给了一个解，但逻辑漏洞还很多，实际上是错误的
// 从数据量可以看出解法应当是O(nlogn)的
class Solution {
public:
    int dp[100005]; // 目前为止长度为i的最长递增子序列的最小结尾
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& x, const vector<int>& y) {
                 return x[0] != y[0] ? x[0] < y[0] : y[1] < x[1];
             });
        int n = envelopes.size();
        dp[1] = envelopes[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (envelopes[i][1] > dp[ans]) {
                ans++;
                dp[ans] = envelopes[i][1];
            } else {
                int l = 0;
                int r = ans;
                while (l + 1 != r) {
                    int m = l + (r - l) / 2;
                    if (dp[m] >= envelopes[i][1]) //
                    {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                dp[r] = envelopes[i][1];
            }
        }
        return ans;
    }
};
// 1.sort排序，w从小到大，h从大到小
// 2.按h求最长递增子序列
// 一、正确性论证
// 分类讨论证明即可
// 二、算法灵感来源

