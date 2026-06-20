class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return nums[0];

        int pre = 1, suff = 1, mxProduct = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(!pre)
            pre = 1;

            if(!suff)
            suff = 1;

            pre*=nums[i];
            suff*=nums[n-i-1];
            mxProduct = max({mxProduct,pre,suff});
        }
        return mxProduct;
    }
};