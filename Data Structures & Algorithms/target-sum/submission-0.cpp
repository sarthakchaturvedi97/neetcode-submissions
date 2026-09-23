class Solution {
public:
    int checkTargetSum(vector<int>& nums, int sum, int n, int **dp)
    {
        if(!n)
        return sum == 0 ? 1 : 0;

        if(dp[n][sum]!=-1)
        return dp[n][sum];

        if(nums[n-1]<=sum)
        return dp[n][sum] = checkTargetSum(nums,sum-nums[n-1],n-1,dp) + checkTargetSum(nums,sum,n-1,dp);
        else
        return dp[n][sum] = checkTargetSum(nums,sum,n-1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        target = abs(target);
        for(int i=0;i<n;i++)
        sum+=nums[i];

        if((sum+target)%2 || sum<target)
        return 0;

        sum = (sum+target)/2;

        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        dp[i] = new int[sum+1];

        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=sum;j++)
        //     dp[i][j] = -1;
        // }

        for(int i=0;i<=n;i++)
        dp[i][0] = 1;

        for(int j=1;j<=sum;j++)
        dp[0][j] = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
        //return checkTargetSum(nums,sum,n,dp);
    }
};