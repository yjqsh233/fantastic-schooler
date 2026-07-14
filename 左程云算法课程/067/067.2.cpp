class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        //对起点可能做枚举 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(f(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    //能否以[i,j]为子串k的起点？
    bool f(vector<vector<char>>&board,string w,int i,int j,int k)
    {   int m=board.size();
        int n=board[0].size();
        //basecase:w结尾和board匹配 
        if(k==w.size()-1&&i>=0&&i<m&&j>=0&&j<n&&w[k]==board[i][j])
        { 
            return true;
        }
        if(i<0||i>=m||j<0||j>=n||w[k]!=board[i][j])
        {
            return false;
        }
        char temp=board[i][j];
        board[i][j]='0';//通过改变原字符的值来避免“回头路” 
        bool ans=f(board,w,i+1,j,k+1)||f(board,w,i-1,j,k+1)||f(board,w,i,j+1,k+1)||f(board,w,i,j-1,k+1);
        board[i][j]=temp;
        return ans;

    }
};

//递归搜索，特征是数据量小；
//为什么这里的递归不能改DP？——因为可变参数复杂——因为记录路径需要改变board参数，i，j以及word的k
