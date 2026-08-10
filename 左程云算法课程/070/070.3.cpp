// https://leetcode.cn/problems/maximum-sum-circular-subarray/submissions/
class Solution {
public:
    int dp1[30005]; // dp[i]表示以i结尾子数组最大值
    int dp2[30005]; // dp[i]表示以i结尾子数组最小值
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        dp1[0] = dp2[0] = nums[0];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int ans = max(dp1[0], sum - dp2[0]);
        for (int i = 1; i < n; i++) {
            dp1[i] = max(nums[i], nums[i] + dp1[i - 1]);
            dp2[i] = min(nums[i], nums[i] + dp2[i - 1]);
            if (sum - dp2[i] != 0) {
                ans = max(ans, max(dp1[i], sum - dp2[i]));
            }
        }
        return ans;
    }
};
// 仿佛有“某种灵感”在帮助我答题，我的直觉指明了前进的方向
// 这种感觉真是不错
// 另外，解决环形数组中的问题是否总能尝试借由直线情形的问题解决？ 
class Solution {
public:
    int dp1; 
    int dp2; 
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        dp1 = dp2 = nums[0];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int ans = max(dp1, sum - dp2);
        for (int i = 1; i < n; i++) {
            dp1 = max(nums[i], nums[i] + dp1);
            dp2 = min(nums[i], nums[i] + dp2);
            if (sum - dp2 != 0) {
                ans = max(ans, max(dp1, sum - dp2));
            }
        }
        return ans;
    }
};
// 轻松完成空间压缩的优化，下面比较一下性能
// before：8ms/42.92MB
// after：0ms/42.64MB ，时间常数优化的还是挺多的
