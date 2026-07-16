class Solution {
public:
    bool dp
        [105]
        [105]; // dp[i][j]表示s1前i个字符和s2前j个字符能不能交错组成s3的前i+j个字符
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) {
            return false;
        }
        dp[0][0]=true;
        int flag1 = 0;
        for (int i = 1; i <= len1; i++) {
            if (s1[i - 1] != s3[i - 1]) {
                flag1 = 1;
            }
            if (flag1 == 0) {
                dp[i][0] = true;
            } else {
                dp[i][0] = false;
            }
        }
        int flag2 = 0;
        for (int j = 1; j <= len2; j++) {
            if (s2[j - 1] != s3[j - 1]) {
                flag2 = 1;
            }
            if (flag2 == 0) {
                dp[0][j] = true;
            } else {
                dp[0][j] = false;
            }
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == true) {
                    dp[i][j] = true;
                }
                if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == true) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[len1][len2];
    }
};
//v1从底到顶的DP
//0ms/8.97MB
 class Solution {
public:
    bool dp
        [105]; // dp[i][j]表示s1前i个字符和s2前j个字符能不能交错组成s3的前i+j个字符
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) {
            return false;
        }
        dp[0] = true;

        int flag2 = 0;
        for (int j = 1; j <= len2; j++) {
            if (s2[j - 1] != s3[j - 1]) {
                flag2 = 1;
            }
            if (flag2 == 0) {
                dp[j] = true;
            } else {
                dp[j] = false;
            }
        }
        int flag1 = 0;
        for (int i = 1; i <= len1; i++) {
            if (s1[i - 1] != s3[i - 1]) {
                flag1 = 1;
            }
            if (flag1 == 0) {
                dp[0] = true;
            } else {
                dp[0] = false;
            }

            for (int j = 1; j <= len2; j++) {
                if (s1[i - 1] == s3[i + j - 1] && dp[j] == true) {
                    dp[j] = true;
                }
                else if (s2[j - 1] == s3[i + j - 1] && dp[j - 1] == true) {
                    dp[j] = true;
                }
                else
                {
                    dp[j]=false;
                }
            }
        }
        return dp[len2];
    }
};
//v2空间压缩
//0ms/8.20MB 
