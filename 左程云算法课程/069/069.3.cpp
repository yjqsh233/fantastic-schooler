class Solution {
public:
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={2,1,-1,-2,-2,-1,1,2};
    double knightProbability(int n, int k, int row, int column) {
        return f(n,k,row,column)/pow(8,k);
    }
    //从(r,c)出发再跑k次还在nxn棋盘上的方案数是多少？
    bool check(int n,int r,int c)
    { if(r>=0&&r<=n-1&&c>=0&&c<=n-1)
     {return true;}
     else{return false;}
    }
    int f(int n,int k,int r,int c)
    { if(k==0)
     { return check(n,r,c)==true?1:0;
     }
      int ans=0;
      for(int i=0;i<8;i++)
      { if(check(n,r+dx[i],c+dy[i])==true)
       { ans+=f(n,k-1,r+dx[i],c+dy[i]);
       }
      }
      return ans;
    }
};
//暴力递归版本 
//TLE 50pts
class Solution {
public:
    int dx[8]={1,2,2,1,-1,-2,-2,-1};
    int dy[8]={2,1,-1,-2,-2,-1,1,2};
    double dp[105][26][26];
    int k0;
    double knightProbability(int n, int k, int row, int column) {
       for(int i=0;i<=k;i++)
       {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {dp[i][j][k]=-1;}
        }
       }
     
        k0=k;
        return f(n,k,row,column);
    }
    //从(r,c)出发再跑k次还在nxn棋盘上的方案数是多少？
    bool check(int n,int r,int c)
    { if(r>=0&&r<=n-1&&c>=0&&c<=n-1)
     {return true;}
     else{return false;}
    }
    double f(int n,int k,int r,int c)
    { if(k==0)
     { return check(n,r,c)==true?1:0;//
     }
     if(dp[k][r][c]!=-1)
     { return dp[k][r][c];
     }
      double ans=0;
      for(int i=0;i<8;i++)
      { if(check(n,r+dx[i],c+dy[i])==true)
       { ans+=f(n,k-1,r+dx[i],c+dy[i])/8;
       }
      }
      dp[k][r][c]=ans;
      return ans;
    }
};
//涉及到超大数的处理和计算，这里考虑算出每一步的中间概率
//为什么会产生nan的结果？ 
 //memset的局限性：不能处理double类型的数组
//记忆化搜索就过了，性能还是不错的
//接下来的从底到顶的DP版本、空间压缩版本还需要补充 
