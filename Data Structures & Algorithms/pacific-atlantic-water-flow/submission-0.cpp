class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        for(auto &dir: directions)
        {
            int x = i+dir[0], y = j+dir[1];
            if(x<0 || y<0 || x>=m || y>= n || visited[x][y] || heights[x][y]<heights[i][j])
            continue;

            dfs(heights,x,y,m,n,visited);
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<int>> result;

        for(int i=0;i<m;i++)
        dfs(heights,i,0,m,n,pacific);

        for(int j=0;j<n;j++)
        dfs(heights,0,j,m,n,pacific);

        for(int i=0;i<m;i++)
        dfs(heights,i,n-1,m,n,atlantic);

        for(int j=0;j<n;j++)
        dfs(heights,m-1,j,m,n,atlantic);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                result.push_back({i,j});
            }
        }
        return result;    
    }
};