class Solution {
public:
    int getUniquePath(int **dp, int m, int n)
    {
        if(!m || !n)
        return dp[m][n] = 1;

        if(dp[m][n]!=-1)
        return dp[m][n];

        return dp[m][n] = getUniquePath(dp,m-1,n) + getUniquePath(dp,m,n-1);
    }
    int uniquePaths(int m, int n) {
        int **dp = new int*[m];
        for(int i=0;i<m;i++)
        dp[i] = new int[n];

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            dp[i][j] = -1;
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!i || !j)
                dp[i][j] = 1;
                else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        //return getUniquePath(dp,m-1,n-1);
    }
};