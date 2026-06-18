class Solution {
public:
    bool checkPartition(vector<int>& nums, int n, int sum, int** dp)
    {
        if(!sum)
        return true;

        if(!n)
        return false;

        if(dp[n][sum]!=-1)
        return dp[n][sum];

        if(nums[n-1]<=sum)
        return dp[n][sum] = checkPartition(nums,n-1,sum-nums[n-1],dp) || checkPartition(nums,n-1,sum,dp);
        else
        return dp[n][sum] = checkPartition(nums,n-1,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        if(sum%2)
        return false;

        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        dp[i] = new int[(sum/2)+1];

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=(sum/2);j++)
            dp[i][j] = -1;
        }

        return checkPartition(nums,n,sum/2,dp);
    }
};