class Solution {
public:
    void getSubsets(vector<int>& nums,int n, vector<int> singleResult, vector<vector<int>>& result)
    {
        if(!n)
        {
            if(find(result.begin(),result.end(),singleResult) == result.end())
            result.push_back(singleResult);
            return;
        }

        vector<int> op = singleResult;
        vector<int> op2 = singleResult;

        op2.push_back(nums[n-1]);
        getSubsets(nums,n-1,op,result);
        getSubsets(nums,n-1,op2,result);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> singleResult;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        getSubsets(nums,nums.size(),singleResult,result);
        return result;
    }
};