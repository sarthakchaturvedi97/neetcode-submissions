class Solution {
public:
    void getMaxArea(vector<vector<int>>& grid, int &area, int i,int j, int m, int n)
    {
        if(i<0 || j<0 || i == m || j == n || grid[i][j] != 1)
        return;

        area++;
        grid[i][j] = 2;
        getMaxArea(grid,area,i,j+1,m,n);
        getMaxArea(grid,area,i+1,j,m,n);
        getMaxArea(grid,area,i,j-1,m,n);
        getMaxArea(grid,area,i-1,j,m,n);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, mxArea = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    getMaxArea(grid,area,i,j,m,n);
                    mxArea = max(area,mxArea);
                    area = 0;
                }
            }
        }
        return mxArea;
    }
};