/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mxSum = INT_MIN;
    int getMaxPathSum(TreeNode* root)
    {
        if(!root)
        return 0;

        int left = getMaxPathSum(root->left);
        int right = getMaxPathSum(root->right);

        mxSum = max({root->val,root->val+left,root->val+right,root->val+left+right,mxSum});
        return max({root->val,root->val+left,root->val+right});
    }
    int maxPathSum(TreeNode* root) {
        getMaxPathSum(root);
        return mxSum;
    }
};