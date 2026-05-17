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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> result;
        vector<int> singleResult;
        while(!q.empty())
        {
            TreeNode* tp = q.front();
            q.pop();
            if(tp == NULL)
            {
                result.push_back(singleResult);
                singleResult.clear();
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                singleResult.push_back(tp->val);
                if(tp->left)
                q.push(tp->left);

                if(tp->right)
                q.push(tp->right);
            }
        }
        return result;
    }
};