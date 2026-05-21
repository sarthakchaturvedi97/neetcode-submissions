class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> result(256,-1);
        int st = -1, mxLen = 0;
        for(int i=0;i<s.length();i++)
        {
            if(result[s[i]]>st)
            st = result[s[i]];

            result[s[i]] = i;
            mxLen = max(mxLen,i-st);
        } 
        return mxLen;
    }
};