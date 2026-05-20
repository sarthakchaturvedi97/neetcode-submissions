class Solution {
public:
    void getSubsets(vector<int>& nums, vector<int> singleResult, vector<vector<int>>& result, int i, int n)
    {
        if(i == n)
        {
            result.push_back(singleResult);
            return;
        }

        vector<int> op1 = singleResult;
        vector<int> op2 = singleResult;
        op2.push_back(nums[i]);
        getSubsets(nums,op1,result,i+1,n);
        getSubsets(nums,op2,result,i+1,n);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> singleResult;
        getSubsets(nums,singleResult,result,0,nums.size());
        return result;
    }
};