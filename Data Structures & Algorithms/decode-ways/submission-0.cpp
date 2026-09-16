class Solution {
public:
    int getCoding(const string &s, int p, int &n, vector<int> &dp)
    {
        if(dp[p] != -1)
        return dp[p];

        if(s[p] == '0')
        return dp[p] = 0;

        int result = getCoding(s,p+1,n,dp);
        if(p<n-1 && (s[p] == '1' || (s[p] == '2' && s[p+1]<'7')))
        result+=getCoding(s,p+2,n,dp);
        return dp[p] = result;
    }
    int numDecodings(string s) {
       int n = s.size();
       vector<int> dp(n+1,-1);
       dp[n] = 1;
       return n?getCoding(s,0,n,dp):0;
    }
};