class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for(int i=0;i<n;i++)
        mp[nums[i]]++;

        for(const auto& entry: mp)
        freq[entry.second].push_back(entry.first);

        vector<int> result;
        for(int i=freq.size()-1;i>=0;i--)
        {
            for(int n: freq[i])
            {
                result.push_back(n);
                if(result.size() == k)
                return result;
            }
        }
        return result;
    }
};