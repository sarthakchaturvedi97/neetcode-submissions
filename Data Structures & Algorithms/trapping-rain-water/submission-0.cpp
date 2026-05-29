class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2)
        return 0;

        int result = 0, n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        for(int i=1;i<n;i++)
        leftMax[i] = max(leftMax[i-1],height[i]);
        
        for(int i=n-2;i>=0;i--)
        rightMax[i] = max(rightMax[i+1],height[i]);

        for(int i=0;i<n;i++)
        result+=min(leftMax[i],rightMax[i])-height[i];

        return result;
    }
};