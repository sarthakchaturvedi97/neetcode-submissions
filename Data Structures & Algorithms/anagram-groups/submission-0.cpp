class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> count(26,0);
            for(char ch : strs[i])
            count[ch-'a']++;

            string key = to_string(count[0]);
            for(int i=1;i<26;i++)
            key+=','+to_string(count[i]);

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        result.push_back(itr->second);

        return result;
    }
};