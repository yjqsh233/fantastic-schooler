//https://leetcode.cn/problems/minimum-cost-for-tickets/submissions/
class Solution {
public:
    int durations[3] = {1, 7, 30}; // 必须标明数组大小
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return f(days, costs, 0);
    }
    // 递归函数,表示从i下标对应days到n-1下标对应days所需要的最低消费,且规定i对应的这一天需要买票
    int f(vector<int>& days, vector<int>& costs, int i) {
        int n = days.size();
        int ans = 9999999;
        if (i == n) {
            return 0;
        }
        for (int k = i, j = 0; j <= 2; j++) {
            while (k < n &&
                   days[k] < durations[j] + days[i]) // k最大到days右边界
            {
                k++;
            }
            ans = min(ans, costs[j] + f(days, costs, k));
        }
        return ans;
    }
    // 暴力递归思路，重复调用过多，TLE
    // 设计递归函数f：
    //f可变参数设计和函数的含义 
	//1.basecase的设计
	//2.尝试策略：枚举 
};

class Solution {
public:
    int durations[3] = {1, 7, 30}; // 必须标明数组大小
    int dp[370];
    const int MAX = 9999999;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return f(days, costs, 0);
    }
    // 递归函数,表示从i下标对应days到n-1下标对应days所需要的最低消费,且规定i对应的这一天需要买票
    int f(vector<int>& days, vector<int>& costs, int i) {
        int n = days.size();
        int ans = MAX;
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i == n) {
            return 0;
        }
        for (int k = i, j = 0; j <= 2; j++) {
            while (k < n &&
                   days[k] < durations[j] + days[i]) // k最大到days右边界
            {
                k++;
            }
            ans = min(ans, costs[j] + f(days, costs, k));
        }
        dp[i] = ans;
        return ans;
    }
};
// 暴力递归改记忆化搜索
// 仅仅是增加了一个DP缓存表，涉及操作一是在递归之前查一查表；二是在递归之后记录一下

class Solution {
public:
    int durations[3] = {1, 7, 30}; // 必须标明数组大小
    int dp[370];
    const int MAX = 9999999;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        int n = days.size();
        for (int i = n - 1; i >= 0; i--) {
            int ans = MAX;
            dp[n] = 0;
            for (int k = i, j = 0; j <= 2; j++) {
                while (k < n &&
                       days[k] < durations[j] + days[i]) // k最大到days右边界
                {
                    k++;
                }
                ans = min(ans, costs[j] + dp[k]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
// 记忆化搜索改自底到顶的递推DP
// 1.dp表覆盖了递归函数f的所有功能，f的basecase对应dp初始化；dp[i]对应f(..,..,i)
// 2.增加了一个从简单到复杂方向递推的逻辑
