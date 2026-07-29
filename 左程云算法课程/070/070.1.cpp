//https://leetcode.cn/problems/maximum-subarray/
class Solution {
public:
    int dp[100005];
    int sum[100005];//sum[i-1]是前i个数的前缀和
    int smaller[100005];//smaller[i]是前i个数前缀和中最小的
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        dp[0]=sum[0]=smaller[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i];
            if(sum[i]<=smaller[i-1])
            { smaller[i]=sum[i];
            }
        }
        for(int i=2;i<n;i++)
        {   
            dp[i]=max(dp[i-1],sum[i]-smaller[i-1]);
        }
        return dp[n-1];
    }
};
//对于这个问题我感觉自己已经有了很好的直觉，却在实现时出现了一些问题
class Solution {
public:
    int dp[100005];
    int sum[100005];//sum[i-1]是前i个数的前缀和
    int smaller[100005];//smaller[i-1]是前i个数前缀和中最小的
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        dp[0]=sum[0]=smaller[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i];
            smaller[i]=min(smaller[i-1],sum[i]);
        }
        for(int i=1;i<n;i++)
        {   
            dp[i]=max(dp[i-1],sum[i]-smaller[i-1]);
        }
        return dp[n-1];
    }
};
//修了smaller数组的一个BUG，但还没过（70pts左右），且样例仍然没全过 
//实际上问题在于：我们可以smaller[1-n-1]为0的 
class Solution {
public:
    int dp[100005];
    int sum[100005];//sum[i-1]是前i个数的前缀和
    int smaller[100005];//smaller[i-1]是前i个数前缀和中最小的
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {return nums[0];}
        dp[0]=sum[0]=nums[0];
        smaller[0]=min(0,nums[0]);
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i];
            smaller[i]=min(smaller[i-1],min(sum[i],0));
        }
        for(int i=1;i<n;i++)
        {   
            dp[i]=max(dp[i-1],sum[i]-smaller[i-1]);
        }
        return dp[n-1];
    }
};
//现在简单的过了一下一维从底到顶的DP
//性能一般还，需再做一些空间压缩 
//代码简约性还有提升空间 
class Solution {
public:
    int dp[100005];//dp[i]以nums[i]结尾的连续子数组最大和
    int maxSubArray(vector<int>& nums) {
        dp[0]=nums[0];
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++)
        { dp[i]=max(dp[i-1]+nums[i],nums[i]);
          ans=max(ans,dp[i]);
        }
        return ans;
    }
};
//该DP定义是更加简洁的
//一旦我们定义出一个好的DP，问题就迎刃而解
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        for(int i=1,pre=nums[0];i<n;i++)
        { pre=max(pre+nums[i],nums[i]);
          ans=max(ans,pre);
        }
        return ans;
    }
};
//该DP定义是更加简洁的
//一旦我们定义出一个好的DP，问题就迎刃而解 
