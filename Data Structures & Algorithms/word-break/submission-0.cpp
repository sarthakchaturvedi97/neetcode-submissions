class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int mxLen = 0;
        for(const string& word: wordDict)
        {
            st.insert(word);
            mxLen = max(mxLen,(int)word.length());
        }

        int n = s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;

        for(int i=1;i<=n;i++)
        {
            for(int len=1;len<=mxLen && len<=i;len++)
            {
                int j = i-len;

                if(dp[j] && st.count(s.substr(j,len)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};