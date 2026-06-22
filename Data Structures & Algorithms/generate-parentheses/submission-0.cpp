class Solution {
public:
    void getResult(int open, int close, string input, vector<string>& result)
    {
        if(!open && !close)
        {
            result.push_back(input);
            return;
        }

        if(open)
        {
            string op = input;
            op.push_back('(');
            getResult(open-1,close,op,result);
        }

        if(open<close)
        {
            string op = input;
            op.push_back(')');
            getResult(open,close-1,op,result);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        getResult(n,n,"",result);
        return result;
    }
};