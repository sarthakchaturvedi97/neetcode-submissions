class Solution {
public:
    int getResult(vector<int> nums, int start, int end)
    {
        int maxRob = 0, prevRob = 0;
        for(int i = start;i<=end;i++)
        {
            int temp = max(maxRob,prevRob+nums[i]);
            prevRob = maxRob;
            maxRob = temp;
        }
        return maxRob;
    }
    int rob(vector<int>& nums) {
        return nums.size() == 1?nums[0]:max(getResult(nums,0,nums.size()-2),getResult(nums,1,nums.size()-1));
    }
};