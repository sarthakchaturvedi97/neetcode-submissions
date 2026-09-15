class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        unordered_map<int,int> mp;
        vector<int> que = queries, result;
        sort(intervals.begin(),intervals.end());
        sort(que.begin(),que.end());
        int i = 0, n = intervals.size();
        for(int q: que)
        {
            while(i<n && intervals[i][0]<=q)
            {
                int left = intervals[i][0], right = intervals[i++][1];
                pq.push({right-left+1,right});
            }

            while(pq.size() && pq.top()[1]<q)
            pq.pop();

            mp[q] = pq.empty()?-1:pq.top()[0];
        }

        for(int q: queries)
        result.push_back(mp[q]);

        return result;
    }
};