class Solution {
public:
    void getIslandsCount(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        if(i == m || j == n || i<0 || j<0 || grid[i][j]!='1')
        return;

        grid[i][j] = '2';
        getIslandsCount(grid,i,j+1,m,n);
        getIslandsCount(grid,i+1,j,m,n);
        getIslandsCount(grid,i,j-1,m,n);
        getIslandsCount(grid,i-1,j,m,n);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, m = grid.size(),n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    getIslandsCount(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};