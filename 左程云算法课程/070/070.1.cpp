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
