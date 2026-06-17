class Solution {
public:
    bool isPalindrome(string palindromeString)
    {
        int i = 0, j = palindromeString.size()-1;
        while(i<j)
        {
            if(palindromeString[i]!=palindromeString[j])
            return false;

            i++;
            j--;
        }
        return true;
    }
    void getPartition(vector<vector<string>>& result, vector<string> singleResult, int index,string s)
    {
        if(index == s.length())
        {
            result.push_back(singleResult);
            return;
        }

        string palindromeString;
        for(int i=index;i<s.length();i++)
        {
            palindromeString+=s[i];
            if(isPalindrome(palindromeString))
            {
                singleResult.push_back(palindromeString);
                getPartition(result,singleResult,i+1,s);
                singleResult.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> singleResult;
        getPartition(result,singleResult,0,s);
        return result;
    }
};