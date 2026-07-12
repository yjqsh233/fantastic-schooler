//https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/description/
class Solution {
public:
    const int p = 1e9 + 7;
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return (fib(n - 1) % p + fib(n - 2) % p) % p;
    }
// 递归方法，时间复杂度为O(2^n)。这题数量100，显然过不了
;}
class Solution {
public:
    long long dp[105];
    const int p = 1e9 + 7;
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        //初始化dp表
        dp[0] = 0;
        dp[1] = 1;
        //递推解得dp[n]
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] % p + dp[i - 2] % p) % p;
        }
        return dp[n] % p;
    }
};
//这是自下而上的递推DP，时间复杂度O(n)

class Solution {
public:
    long long Last = 1;
    long long Last_last = 0;
    const int p = 1e9 + 7;
    int fib3(int n) {
        if (n == 0) {
            return Last_last;
        }
        if (n == 1) {
            return Last;
        }

        for (int i = 2; i <= n; i++) {
            long long cur = (Last % p + Last_last % p) % p;
            Last_last = Last;
            Last = cur;
        }
        return Last % p;
    }
};
// 这是fib2的空间优化版本，空间复杂度O(1) 
