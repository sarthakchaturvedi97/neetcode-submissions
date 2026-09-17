class Solution {
public:
    int jump(vector<int>& nums) {
        int mxIndex = 0, jumps = 0, currentJumpMax = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            mxIndex = max(mxIndex,nums[i]+i);
            if(i == currentJumpMax)
            {
                currentJumpMax = mxIndex;
                jumps++;
            }
        }
        return jumps;
    }
};