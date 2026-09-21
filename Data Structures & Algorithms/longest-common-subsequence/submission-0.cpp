class Solution {
public:
    int getLongestCommonSubsequence(string text1, string text2, int m, int n, int **dp)
    {
        if(!m || !n)
        return 0;

        if(dp[m][n]!=-1)
        return dp[m][n];

        if(text1[m-1] == text2[n-1])
        return dp[m][n] = 1 + getLongestCommonSubsequence(text1,text2,m-1,n-1,dp);
        else
        return dp[m][n] = max(getLongestCommonSubsequence(text1,text2,m-1,n,dp),getLongestCommonSubsequence(text1,text2,m,n-1,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int **dp = new int*[m+1];
        for(int i=0;i<=m;i++)
        dp[i] = new int[n+1];

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            dp[i][j] = -1;
        }

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(!i || !j)
                dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
        //return getLongestCommonSubsequence(text1,text2,m,n,dp);
    }
};