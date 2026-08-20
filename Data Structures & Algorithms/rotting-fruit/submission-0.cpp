class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, rotten = 0, m = grid.size(), n = grid[0].size(), count = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                fresh++;
                else if(grid[i][j] == 2)
                q.push({i,j});
            }
        }

        if(!fresh)
        return 0;

        vector<pair<int,int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};

        while(!q.empty())
        {
            int sz = q.size();
            bool freshlyRotten = false;

            for(int i=0;i<sz;i++)
            {
                auto [x,y] = q.front();
                q.pop();

                for(auto [dx,dy]: directions)
                {
                    int nX = x+dx;
                    int nY = y+dy;

                    if(nX>=0 && nY>=0 && nX<m && nY<n && grid[nX][nY] == 1)
                    {
                        freshlyRotten = true;
                        q.push({nX,nY});
                        grid[nX][nY] = 2;
                        fresh--;
                    }
                }
            }

            if(freshlyRotten)
            count++;
        }
        return fresh!=0?-1:count;
    }
};