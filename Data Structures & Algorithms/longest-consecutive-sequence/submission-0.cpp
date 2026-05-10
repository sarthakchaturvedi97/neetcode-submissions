class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int minLength = 1, maxLength = 1;
        for(int i=0;i<nums.size();i++)
        st.insert(nums[i]);

        for(auto itr=st.begin();itr!=st.end();itr++)
        {
            if(st.find(*itr - 1)!=st.end())
            minLength++;
            else
            minLength = 1;

            maxLength = max(minLength,maxLength);
        }
        return nums.size()>0?maxLength:0;
    }
};