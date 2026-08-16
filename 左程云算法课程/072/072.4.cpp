// https://leetcode.cn/problems/maximum-length-of-pair-chain/submissions/
class Solution {
public:
    int dp[1005];
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& x, const vector<int>& y) {
                 return x[0] < y[0];
             });
        int n = pairs.size();
        dp[1] = pairs[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > dp[ans]) {
                ans++;
                dp[ans] = pairs[i][1];
            } else {
                int l = 0;
                int r = ans;
                while (l + 1 != r) {
                    int m = l + (r - l) / 2;
                    if (dp[m] >= pairs[i][0]) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                dp[r] = pairs[i][1];
            }
        }
        return ans;
    }
};
// 听过一遍这个技巧的思路，却没能第一次完成，DEBUG
class Solution {
public:
    int dp[1005];
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& x, const vector<int>& y) {
                 return x[0] < y[0];
             });
        int n = pairs.size();
        dp[1] = pairs[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > dp[ans]) {
                ans++;
                dp[ans] = pairs[i][1];
            } else {
                int l = 0;
                int r = ans;
                while (l + 1 != r) {
                    int m = l + (r - l) / 2;
                    if (dp[m] >= pairs[i][1]) // 1
                    {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                if (pairs[i][1] <= dp[ans]) // 2注意是否会超出dp右边界
                {
                    dp[r] = pairs[i][1];
                }
            }
        }
        return ans;
    }
};
// 相比原模型有不少细节上的变化
