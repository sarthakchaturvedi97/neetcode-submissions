class Solution {
public:
    int expand(const string &s, int left, int right, int n)
    {
        int count = 0;
        while(left>=0 && right<n && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count = 0, n = s.length();
        for(int i=0;i<n;i++)
        {
            count += expand(s,i,i,n);
            count += expand(s,i,i+1,n);
        }
        return count;
    }
};