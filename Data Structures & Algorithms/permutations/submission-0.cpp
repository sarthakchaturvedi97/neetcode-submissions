class Solution {
public:
    void getPermutation(vector<int>& nums, int index, int n, vector<vector<int>>& result)
    {
        if(index == n)
        {
            result.push_back(nums);
            return;
        }

        for(int i = index;i<n;i++)
        {
            swap(nums[index],nums[i]);
            getPermutation(nums,index+1,n,result);
            swap(nums[index],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        getPermutation(nums,0,nums.size(),result);
        return result;
    }
};