class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        visited[node] = true;
        for(auto nbr: adj[node])
        {
            if(!visited[nbr])
            dfs(adj,visited,nbr);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for(int node=0;node<n;node++)
        {
            if(!visited[node])
            {
                dfs(adj,visited,node);
                count++;
            }
        }
        return count;
    }
};
