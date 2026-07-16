class Solution {
public:
    int dp[505][505];//dp[i][j]表示把word1[0...i-1]转化为word2[0...j-1]所需的最少操作数
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {   if(word1[i-1]==word2[j-1])
             {
                dp[i][j]=dp[i-1][j-1];
             }
             else
             {
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
             }
            }
        }
        return dp[n][m];
    }
};
//常见的思路就是去考虑对末尾如何变换？ 是否变换？ 
//状态转移方程如何讨论？
//1.word1[i-1]“被变换”
//a.考虑word1[i-1]替换为word2[j-1](word1[i-1]!=word2[j-1])
//b.word1[0-i-1]变换为word2[0-j-2]后“插入”word2[j-1]
//c.word1[0-i-2]变换为word2[0-j-1]后“删除”word1[i-1]
//ps：这里我们只需要确保操作种类的覆盖，word1[0-i-1]->word2[0-j-3]后双插入是覆盖在b中的情况 
//2.word1[i-1]不会“被变换”
//a.word1[i-1]==word2[j-1]直接保留，无需操作
class Solution {
public:
    int dp
        [505]; // dp[i][j]表示把word1[0...i-1]转化为word2[0...j-1]所需的最少操作数

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }

        for (int j = 0; j <= m; j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= n; i++) {
            int prev = i - 1;
            dp[0] = i - 1; //
            for (int j = 1; j <= m; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j], min(dp[j - 1], prev)) + 1;
                }
                prev = temp;
            }
        }
        return dp[m];
    }
};
// 这是空间压缩的版本
// 值得注意的是，这里由于初始条件dp[i][0]=i,我们每一次都需要在i层循环里设置dp[0]和初始prev
// 这也再次体现了空间压缩是人为的压榨性能，不是删了i就是压缩的
class Solution {
public:
    int dp
        [505]; // dp[i][j]表示把word1[0...i-1]转化为word2[0...j-1]所需的最少操作数

    int minDistance(string word1, string word2) {
        return edit(word1,word2,1,1,1);
    }
    int edit(string word1,string word2,int a,int b,int c)
    {
        int n = word1.size();
        int m = word2.size();
        if (m == 0) {
            return n*a;
        }
        if (n == 0) {
            return m*b;
        }

        for (int j = 0; j <= m; j++) {
            dp[j] = j*a;
        }
        for (int i = 1; i <= n; i++) {
            int prev = b*(i - 1);
            dp[0] = b*(i - 1); //
            for (int j = 1; j <= m; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j]+b, min(dp[j - 1]+a, prev+c));
                }
                prev = temp;
            }
        }
        return dp[m];
    }
};
// 这是推广了三种操作价值的版本，速度其实会比v2慢不少 
