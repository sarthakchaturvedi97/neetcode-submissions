class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(const string& str: strs)
        result+= to_string(str.size())+'#'+str;
        return result;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while(i!=s.size())
        {
            int j = i;
            while(s[j]!='#')
            j++;
            int length = stoi(s.substr(i,j-i));
            i = j+1;
            j = i+length;
            result.push_back(s.substr(i,length));
            i = j;
        }
        return result;
    }
};
