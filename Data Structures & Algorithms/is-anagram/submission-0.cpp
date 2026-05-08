class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;

        vector<int> result(26,0);
        for(int i=0;i<s.length();i++)
        result[s[i]-'a']++;

        for(int i=0;i<t.length();i++)
        result[t[i]-'a']--;

        for(int i=0;i<26;i++)
        {
            if(result[i])
            return false;
        }
        return true;
    }
};