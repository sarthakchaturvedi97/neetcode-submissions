class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentTank = 0, totalTank = 0, start = 0;
        for(int i=0;i<cost.size();i++)
        {
            totalTank += (gas[i]-cost[i]);
            currentTank += (gas[i]-cost[i]);
            if(currentTank<0)
            {
                currentTank = 0;
                start = i+1;
            }
        }
        return totalTank<0?-1:start;
    }
};