class Solution {
public:
    int findMinDistance(string word1, string word2, int m, int n, int **dp)
    {
        if(!m)
        return n;

        if(!n)
        return m;

        if(dp[m][n]!=-1)
        return dp[m][n];

        if(word1[m-1] == word2[n-1])
        return dp[m][n] = findMinDistance(word1,word2,m-1,n-1,dp);
        else
        return dp[m][n] = 1 + min({findMinDistance(word1,word2,m-1,n,dp),findMinDistance(word1,word2,m,n-1,dp),findMinDistance(word1,word2,m-1,n-1,dp)});
                        // Delete                           // Insert                          // Replace
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int **dp = new int*[m+1];
        for(int i=0;i<=m;i++)
        dp[i] = new int[n+1]{0};

        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     dp[i][j] = -1;
        // }

        for(int i=1;i<=m;i++)
        dp[i][0] = i;

        for(int j=1;j<=n;j++)
        dp[0][j] = j;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                                    //Delete    //Insert    //Replace
            }
        } 
        return dp[m][n];
        // return findMinDistance(word1,word2,m,n,dp);
    }
};