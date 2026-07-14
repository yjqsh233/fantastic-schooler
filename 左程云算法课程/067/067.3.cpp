class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
     int len1=text1.size();
     int len2=text2.size();
     return f(text1,text2,len1,len2);
    }
    //i,j表示字符串[0-i-1]和[0-j-1]的最长公共子序列长度
    int f(string text1,string text2,int i,int j)
    { if(i==0||j==0)
     {
        return 0;
     }

     if(i>=1&&j>=1&&f(text1,text2,i-1,j)==f(text1,text2,i,j-1)&&text1[i-1]==text2[j-1])
     {
        return f(text1,text2,i-1,j-1)+1;
     }
     else 
     {
        return max(f(text1,text2,i-1,j),f(text1,text2,i,j-1));
     }
    }
};
//v1暴力递归版本，TLE但逻辑很可能是对的 

class Solution {
public:
     int dp[1005][1005];
     int longestCommonSubsequence(string text1, string text2) {
     int len1=text1.size();
     int len2=text2.size();
     memset(dp,-1,sizeof(dp));
     return f(text1,text2,len1,len2);
    }
    //i,j表示字符串[0-i-1]和[0-j-1]的最长公共子序列长度
    int f(string text1,string text2,int i,int j)
    { if(i==0||j==0)
     {
        return 0;
     }
     if(dp[i][j]!=-1)
     {
        return dp[i][j];
     }
     if(i>=1&&j>=1&&f(text1,text2,i-1,j)==f(text1,text2,i,j-1)&&text1[i-1]==text2[j-1])
     {  dp[i][j]=f(text1,text2,i-1,j-1)+1;
        return f(text1,text2,i-1,j-1)+1;
     }
     else 
     {  dp[i][j]=max(f(text1,text2,i-1,j),f(text1,text2,i,j-1));
        return max(f(text1,text2,i-1,j),f(text1,text2,i,j-1));
     }
    }
};
//v2记忆化搜索版本
//仍然TLE，理论上改为递推DP也没什么用？
class Solution {
public:
    int dp[1005][1005];
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (i >= 1 && j >= 1 && dp[i - 1][j] == dp[i][j - 1] &&
                    text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len1][len2];
    }
};
//v3递推DP
//实际上比v2快很多，这是为什么？
//时间23ms，内存12.64MB 
class Solution {
public:
    int dp[1005];
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        for (int j = 0; j <= len2; j++) {
            dp[j] = 0;
        }
        for (int i = 1; i <= len1; i++) {
            int prev=0;//存放左上角
            for (int j = 1; j <= len2; j++) {
                int temp=dp[j];//
                if (dp[j] == dp[j - 1] && text1[i - 1] == text2[j - 1]) {
                        dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev=temp;//更新左上角的数
            }
        }

        return dp[len2];
    }
};
//v4 在性能方面又有大的提升：10ms、8.64MB
//空间压缩绝不是简单的删除i行，本质上只有利用图解思考依赖关系这一条路
//这里得到的是关于涉及[i-1,j-1]的空间压缩处理
