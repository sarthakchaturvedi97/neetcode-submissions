class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
        return false;

        vector<int> count(26,0);
        for(int i=0;i<s1.length();i++)
        count[s1[i]-'a']++;

        int i = 0, m = s1.length(), n = s2.length();
        while(i<=n)
        {
            if(i<m && i<n)
            count[s2[i]-'a']--;
            else
            {
                bool flag = true;
                for(int j=0;j<26;j++)
                {
                    if(count[j]!=0)
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag)
                return flag;

                if(i<n)
                {
                    count[s2[i-m]-'a']++;
                    count[s2[i]-'a']--;
                }     
            }
            i++;
        }
        return false;
    }
};