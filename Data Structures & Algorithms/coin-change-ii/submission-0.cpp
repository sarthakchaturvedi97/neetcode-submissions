class Solution {
public:
    int getChange(int amount, vector<int>& coins, int n, int **dp)
    {
        if(!amount)
        return dp[amount][n] = 1;
        
        if(!n)
        return dp[amount][n] = 0;

        if(dp[amount][n]!=-1)
        return dp[amount][n];

        if(coins[n-1]<=amount)
        return dp[amount][n] = getChange(amount-coins[n-1],coins,n,dp) + getChange(amount,coins,n-1,dp);
        else 
        return dp[amount][n] = getChange(amount,coins,n-1,dp);

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int **dp = new int*[amount+1];
        for(int i=0;i<=amount;i++)
        dp[i] = new int[n+1];

        for(int i=0;i<=amount;i++)
        {
            for(int j=0;j<=n;j++)
            dp[i][j] = -1;
        }
        return getChange(amount,coins,n,dp);
    }
};