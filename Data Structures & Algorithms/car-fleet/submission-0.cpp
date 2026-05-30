class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> combination;
        int fleet = 1, n = position.size();
        for(int i=0;i<n;i++)
        combination.push_back({position[i],speed[i]});

        sort(combination.rbegin(),combination.rend());

        double prevTime = (double) (target-combination[0].first)/combination[0].second;
        for(int i=1;i<n;i++)
        {
            double currentTime = (double) (target-combination[i].first)/combination[i].second;
            if(currentTime>prevTime)
            {
                fleet++;
                prevTime = currentTime;
            }
        }
        return fleet;
    }
};