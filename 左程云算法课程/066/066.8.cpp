class Solution {
public:
    const int p = 1e9 + 7;
    long long dp[30];
    int distinctSubseqII(string s) {
        int n = s.size();
        long long cnt = 1;
        for (int i = 0; i < n; i++) {
            int newcnt = (cnt % p - dp[s[i] - 'a'] % p + p) % p;
            cnt = (cnt % p + newcnt % p+p) % p;
            dp[s[i] - 'a'] = (dp[s[i] - 'a'] % p + newcnt % p) % p;
        }
        if(cnt==0)
        { return 1e9+6;
        }
        return cnt - 1;
    }
};
//这个地方的hack有点离谱
//状态定义暂时背过，之后回过头来总结
