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
    void getGoodNodes(TreeNode* root, int& countNodes, int maxValue)
    {
        if(!root)
        return;

        if(root->val>=maxValue)
        {
            ++countNodes;
            maxValue = root->val;
        }

        getGoodNodes(root->left,countNodes, maxValue);
        getGoodNodes(root->right,countNodes,maxValue);
    }
    int goodNodes(TreeNode* root) {
        int countNodes = 0;
        getGoodNodes(root,countNodes, root->val);
        return countNodes;
    }
};