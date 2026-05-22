class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
        return 0;

        int i=0,j=1,maxProfit=0;
        while(i<prices.size()&&j<prices.size())
        {
            if(prices[i]>=prices[j])
            {
                i++;
                if(i==j)
                j++;
            }
            else
            {
                maxProfit=max(maxProfit,prices[j]-prices[i]);
                j++;
            }
        }
        return maxProfit;
    }
};