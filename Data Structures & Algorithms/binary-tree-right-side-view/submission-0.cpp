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
    void getRightSideView(TreeNode* root, int &mxLevel, int level, vector<int>& result)
    {
        if(!root)
        return;

        if(level>mxLevel)
        {
            result.push_back(root->val);
            mxLevel = level;
        }

        getRightSideView(root->right, mxLevel, level+1, result);
        getRightSideView(root->left, mxLevel, level+1, result);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        int mxLevel = INT_MIN;
        vector<int> result;
        getRightSideView(root,mxLevel,0,result);
        return result;
    }
};