// https://leetcode.cn/problems/Gu0c2T/description/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i += 2) {
            sum1 += nums[i];
        }
        for (int i = 1; i < n; i += 2) {
            sum2 += nums[i];
        }
        return max(sum1, sum2);
    }
};
// 一个错误的贪心，实际上sum当然可以有不同间隔
// 另外，这个问题是否揭示了连续和不连续之间的某种联系 ？
class Solution {
public:
    int dp[105]; // dp[i]表示nums[0-i-1]不连续子数组的最大值
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp[1] = nums[0];
        if (n == 1) {
            return dp[1];
        } else {
            dp[2] = max(nums[0], nums[1]);
        }
        for (int i = 2; i <= n; i++) {
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }
};
// 一开始，我被模型困住了。总想着要套用原模型解决问题
// 之后尝试了用基本的方法来解决：猜测dp状态，答案算是迎刃而解
class Solution {
public:
    int prev, ans; // dp[i]表示nums[0-i-1]不连续子数组的最大值
    int rob(vector<int>& nums) {
        int n = nums.size();
        prev = nums[0];
        if (n == 1) {
            return prev;
        } else {
            ans = max(nums[0], nums[1]);
        }
        for (int i = 3; i <= n; i++) {
            int temp = ans;
            ans = max(nums[i - 1] + prev, ans);
            prev = temp;
        }
        return ans;
    }
};
// 简单做了以下空间优化，比较一下性能
// before:2ms,9.99MB
// after:0ms,10MB
// 发现了一个奇怪的现象：“空间优化”没有优化空间，而是优化了时间
// 1.空间占用的大头不在你的变量里（100个变量占用空间很小的）
// 2.复杂度没有变化，但常数时间优化了几倍
