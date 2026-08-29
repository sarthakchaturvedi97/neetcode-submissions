class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        int n = s.length(), mxPos = 0, st = 0;
        vector<int> result;
        for(int i=0;i<n;i++)
        last[s[i]-'a'] = i;

        for(int i=0;i<n;i++)
        {
            mxPos = max(mxPos,last[s[i]-'a']);
            if(i == mxPos)
            {
                result.push_back(i-st+1);
                st = i+1;
            }
        }
        return result;
    }
};