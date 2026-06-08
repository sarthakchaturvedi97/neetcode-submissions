class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0, star = 0, n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i] == ')')
            left++;
            else if(s[i] == '(')
            right++;
            else
            star++;

            if(left>(right+star))
            return false;
        }
        
        left = 0, right = 0, star = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == ')')
            left++;
            else if(s[i] == '(')
            right++;
            else
            star++;

            if(right>(left+star))
            return false;
        } 
        return true;
    }
};