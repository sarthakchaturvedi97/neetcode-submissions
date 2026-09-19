/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/



class Solution {
public:
    unordered_map<Node*,Node*> mp; 
    void dfs(Node* node)
    {
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto itr: node->neighbors)
        {
            if(mp.find(itr) == mp.end())
            dfs(itr);

            clone->neighbors.push_back(mp[itr]);
        }
        return;
    }  
    Node* cloneGraph(Node* node) {
        if(!node)
        return node;

        dfs(node);
        return mp[node];
    }
};
