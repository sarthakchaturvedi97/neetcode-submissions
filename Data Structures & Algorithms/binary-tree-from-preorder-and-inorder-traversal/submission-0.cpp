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
    int k = 0;
    TreeNode* buildTreeFinal(vector<int>& preorder, vector<int>& inorder, int st, int end)
    {
        if(st>end)
        return NULL;
        int data = preorder[k++], pos = -1;
        TreeNode* root = new TreeNode(data);
        for(int i=st;i<=end;i++)
        {
            if(inorder[i] == data)
            {
                pos = i;
                break;
            }
        }
        root->left = buildTreeFinal(preorder,inorder,st,pos-1);
        root->right = buildTreeFinal(preorder,inorder,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeFinal(preorder,inorder,0,inorder.size()-1);
    }
};