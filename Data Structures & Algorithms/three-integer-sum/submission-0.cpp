class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i && nums[i] == nums[i-1])
            continue;

            int left = i+1, right = n-1;
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0)
                {
                    vector<int> singleResult = {nums[i],nums[left],nums[right]};
                    sort(singleResult.begin(),singleResult.end());
                    result.push_back(singleResult);

                    left++;
                    right--;

                    while(left<right && nums[left] == nums[left-1])
                    left++;

                    while(right>0 && nums[right] == nums[right+1])
                    right--;
                }
                else if(sum>0)
                right--;
                else
                left++;
            }
        }
        return result;
    }
};