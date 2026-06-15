class Solution {
public:
    void getCombinationSum(vector<int>& candidates, int target, int n, vector<int> singleResult, vector<vector<int>>& result)
    {
        if(!n)
        {
            if(!target && (find(result.begin(),result.end(),singleResult)==result.end()))
            result.push_back(singleResult);
            return;
        }

        if(candidates[n-1]<=target)
        {
            vector<int> op1 = singleResult;
            op1.push_back(candidates[n-1]);
            getCombinationSum(candidates,target-candidates[n-1],n,op1,result);
        }
        
        getCombinationSum(candidates,target,n-1,singleResult,result);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> singleResult;
        getCombinationSum(candidates,target,candidates.size(),singleResult,result);
        return result;
    }
};