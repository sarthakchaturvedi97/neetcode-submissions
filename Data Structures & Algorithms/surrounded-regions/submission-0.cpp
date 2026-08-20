class Solution {
public:
    void getSurroundedRegions(vector<vector<char>>& board , int i, int j, int m, int n)
    {
        if(i<0 || j<0 || i == m || j == n || board[i][j] != 'O')
        return;

        board[i][j] = '!';
        getSurroundedRegions(board,i-1,j,m,n);
        getSurroundedRegions(board,i,j-1,m,n);
        getSurroundedRegions(board,i+1,j,m,n);
        getSurroundedRegions(board,i,j+1,m,n);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                getSurroundedRegions(board,i,j,m,n);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O')
                board[i][j] = 'X';
                else if(board[i][j] == '!')
                board[i][j] = 'O';
            }
        }
        return;
    }
};