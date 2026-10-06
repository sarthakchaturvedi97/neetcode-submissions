class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
        return false;

        bool *visited = new bool[n];
        int *parent = new int[n];
        for(int i=0;i<n;i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int src = 0;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int visitedCount = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visitedCount++;
            for(int nbr : adj[node])
            {
                if(visited[nbr] && parent[node]!=nbr)
                return false;
                else if(!visited[nbr])
                {
                    visited[nbr] = true;
                    q.push(nbr);
                    parent[nbr] = node;
                }
            }
        }
        return visitedCount == n;
    }
};
