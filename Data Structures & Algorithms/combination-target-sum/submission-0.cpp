class Solution {
public:
    void getCombinationSum(vector<int> candidates,int target, int n,vector<int> singleAnswer,vector<vector<int>> &result)
    {
        if(!n)
        {
            if(!target && (find(result.begin(),result.end(),singleAnswer) == result.end()))
            result.push_back(singleAnswer);
            return;
        }

        if(candidates[n-1]<=target)
        {
            vector<int> op1 = singleAnswer;
            op1.push_back(candidates[n-1]);
            getCombinationSum(candidates,target-candidates[n-1],n,op1,result);
        }
        
        getCombinationSum(candidates,target,n-1,singleAnswer,result);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> singleAnswer;
        int n = candidates.size();
        getCombinationSum(candidates,target,n,singleAnswer,result);
        return result;
    }
};