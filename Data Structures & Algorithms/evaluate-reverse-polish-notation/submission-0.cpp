class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            string str = tokens[i];
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                int ele2 = st.top();
                st.pop();
                int ele1 = st.top();
                st.pop();
                switch(str[0])
                {
                    case '+':
                    st.push(ele1+ele2);
                    break;
                    case '-':
                    st.push(ele1-ele2);
                    break;
                    case '*':
                    st.push(ele1*ele2);
                    break;
                    case '/':
                    st.push(ele1/ele2);
                }
            }
            else
            st.push(stoi(str));
        }
        return st.top();
    }
};