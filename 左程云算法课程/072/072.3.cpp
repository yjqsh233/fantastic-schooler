// https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/
class Solution {
public:
    int dp[100005];
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = n;
        for (int i = 1; i <= k; i++) // 计算k次最长不下降子序列
        { // 1.计算子数组[arr[i-1],arr[i-1+k]......]
            dp[1] = arr[i - 1];
            int ans = 1;
            for (int j = i - 1 + k; j < n; j += k) {
                if (arr[j] >= dp[ans]) {
                    ans++;
                    dp[ans] = arr[j];
                } else {
                    int l = 0;
                    int r = ans;
                    while (l + 1 != r) {
                        int m = l + (r - l) / 2;
                        if (dp[m] > arr[j]) {
                            r = m;
                        } else {
                            l = m;
                        }
                    }
                    dp[r] = arr[j];
                }
            }
            // 2.计算ans从而得出次数cnt
            cnt -= ans;
        }
        return cnt;
    }
};
// 受了左神的一点启发：cnt=n-ans之和
// 性能已经达到最佳
