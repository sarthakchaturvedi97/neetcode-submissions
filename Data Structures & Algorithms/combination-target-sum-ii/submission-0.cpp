class Solution {
public:
    void getCombinationSum(vector<int>& candidates, int target, int n, vector<int> singleResult, vector<vector<int>>& result)
    {
        if(!n)
        {
            if(!target)
            result.push_back(singleResult);
            return;
        }

        if(candidates[n-1]<=target)
        {
            int element = candidates[n-1];
            vector<int> op = singleResult;
            op.push_back(element);
            getCombinationSum(candidates,target-candidates[n-1],n-1,op,result);

            while(n && candidates[n-1] == element)
            n--;

            n++;
        }

        getCombinationSum(candidates,target,n-1,singleResult,result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> singleResult;
        sort(candidates.begin(),candidates.end());
        getCombinationSum(candidates,target,candidates.size(),singleResult,result);
        return result;
    }
};