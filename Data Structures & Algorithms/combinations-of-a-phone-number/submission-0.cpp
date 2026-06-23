class Solution {
public:
    void getLetterCombinations(string digits, string path, vector<string>& result, unordered_map<int,string>& mp, int index)
    {
        if(index == digits.size())
        {
            result.push_back(path);
            return;
        }

        int ind = digits[index++] - '0';
        string letters = mp[ind];
        for(char &ch: letters)
        {
            path.push_back(ch);
            getLetterCombinations(digits, path, result, mp, index);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
        return {};
        vector<string> result;
        unordered_map<int,string> mp = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9, "wxyz"}};
        getLetterCombinations(digits,"",result,mp,0);
        return result;
    }
};