class Solution {
public:
    bool hoursPossible(vector<int>& piles, int h, long speed, int n)
    {
        long hours = 0;
        for(int i=0;i<n;i++)
        hours += (piles[i]+speed-1)/speed;

        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long st = 1 ,end = INT_MIN, n = piles.size();
        for(int i=0;i<n;i++)
        end = max(end,(long)piles[i]);

        while(st<=end)
        {
            long mid = st + (end-st)/2;
            if(hoursPossible(piles,h,mid,n))
            end = mid-1;
            else
            st = mid+1;
        }
        return st;
    }
};