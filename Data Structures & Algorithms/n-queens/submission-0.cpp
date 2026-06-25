class Solution {
public:
    bool isPossible(vector<string>& board, int i, int j, int n)
    {
        for(int k=0;k<n;k++)
        {
            if(board[i][k] == 'Q' || board[k][j] == 'Q')
            return false;
        }

        int row = i, col = j;
        while(row>=0 && col>=0)
        {
            if(board[row][col] == 'Q')
            return false;

            row--;
            col--;
        }

        row = i, col = j;

        while(row>=0 && col<n)
        {
            if(board[row][col] == 'Q')
            return false;

            row--;
            col++;
        }
        return true;
    }
    bool getSolvedQueens(vector<string>& board, vector<vector<string>>& result, int index, int n)
    {
        if(index == n)
        {
            result.push_back(board);
            return false;
        }

        for(int j=0;j<n;j++)
        {
            if(isPossible(board,index,j,n))
            {
                board[index][j] = 'Q';
                if(getSolvedQueens(board,result,index+1,n))
                return true;

                board[index][j] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        getSolvedQueens(board,result,0,n);
        return result;
    }
};