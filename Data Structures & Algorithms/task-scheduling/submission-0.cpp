class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26,0);
        int sz = tasks.size();
        for(int i=0;i<sz;i++)
        mp[tasks[i]-'A']++;

        for(int i=0;i<26;i++)
        {
            if(mp[i])
            pq.push(mp[i]);
        }

        int time = 0;
        while(!pq.empty())
        {
            vector<int> remaining;
            int cycle = n+1;
            while(cycle && !pq.empty())
            {
                int mxFrequency = pq.top();
                pq.pop();

                if(mxFrequency-1>0)
                remaining.push_back(mxFrequency-1);

                time++;
                cycle--;
            }

            for(int count:remaining)
            pq.push(count);

            if(pq.empty()) 
            break;

            time+=cycle;
        }
        return time;
    }
};