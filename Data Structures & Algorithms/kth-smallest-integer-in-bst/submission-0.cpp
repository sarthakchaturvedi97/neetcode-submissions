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
    int result;
    void getKthSmallest(TreeNode* root,int &k)
    {
        if(!root)
        return;

        getKthSmallest(root->left, k);
        k--;

        if(!k)
        {
            result = root->val;
            return;
        }

        getKthSmallest(root->right, k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!k)
        return root->val;

        getKthSmallest(root,k);
        return result;
    }
};