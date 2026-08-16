class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
                vector<int> mp(26,0);
                        int mxFrequency = 0, countMxFrequency = 0, sz = tasks.size();
                                for(int i=0;i<sz;i++)
                                        {   
                                                    mp[tasks[i]-'A']++;
                                                                if(mp[tasks[i]-'A']>mxFrequency)
                                                                            mxFrequency = mp[tasks[i]-'A'];
                                                                                    }

                                                                                            for(int i=0;i<26;i++)
                                                                                                    {
                                                                                                                if(mp[i] == mxFrequency)
                                                                                                                            countMxFrequency++;
                                                                                                                                    }

                                                                                                                                            int time = (mxFrequency-1)*(n+1) + countMxFrequency;       
                                                                                                                                                    return max(time,sz);
                                                                                                                                                        }
                                                                                                                                                        };