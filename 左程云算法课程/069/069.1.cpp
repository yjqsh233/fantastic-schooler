class Solution {
public:
    int zero_num=0;int one_num=0;
    void calculate(vector<string>& strs,int i)
    {
        int temp0=0,temp1=0;
        for(int j=0;j<strs[i].size();j++)
        { if(strs[i][j]=='0')
         {
            temp0++;
         }
         else
         {
            temp1++;
         }
        }
        zero_num=temp0;
        one_num=temp1;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        return f(strs,0,m,n);
    }
    //函数返回值表示strs[i...]的最大子集长度
    int f(vector<string>&strs,int i ,int z,int o)
    { int n=strs.size();
      //basecase
      if(i==n)
      { return 0;
      }
      //尝试策略是考虑当前“末尾”，如果使用则考虑是否超过z、o；如果不使用则考虑后续i+1
      int p1=f(strs,i+1,z,o);
      int p2=0;
      calculate(strs,i);
      if(zero_num<=z&&one_num<=o)
      {
        p2=f(strs,i+1,z-zero_num,o-one_num)+1;
      }
      return max(p1,p2);
    }
};
//问题仍然出现在设计递归函数的可变参数/DP的状态上
//一开始，我完全没有思路该怎么入手这个问题，以及最重要的是“为什么要走DP这条路”？
//TLE
