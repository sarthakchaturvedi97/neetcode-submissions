/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        return "N,";

        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeString(queue<string> &q)
    {
        string data = q.front();
        q.pop();
        if(data == "N")
        return NULL;

        TreeNode* root = new TreeNode(stoi(data));
        root->left = deserializeString(q);
        root->right = deserializeString(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                q.push(s);
                s="";
            }
            else
            s+= data[i];
        }
        if(!s.empty())
        q.push(s);
        return deserializeString(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));