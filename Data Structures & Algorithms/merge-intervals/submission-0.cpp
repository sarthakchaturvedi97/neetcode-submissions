class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int st = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> result;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            end = max(end,intervals[i][1]);
            else
            {
                result.push_back({st,end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({st,end});
        return result;
    }
};