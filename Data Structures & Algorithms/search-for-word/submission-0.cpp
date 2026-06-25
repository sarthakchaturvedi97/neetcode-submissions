class Solution {
public:
    bool ifWordExist(vector<vector<char>>& board,int i, int j,int k,int m,int n,string word,int len)
    {
        if(k == len)
        return true;

        if( i==m || j==n || i<0 || j<0)
        return false;

        bool found = false;
        if(word[k] == board[i][j])
        {
            char temp = board[i][j];
            board[i][j] = '*';
            found = ifWordExist(board,i+1,j,k+1,m,n,word,len) || ifWordExist(board,i-1,j,k+1,m,n,word,len) || ifWordExist(board,i,j+1,k+1,m,n,word,len) || ifWordExist(board,i,j-1,k+1,m,n,word,len);
            board[i][j] = temp;
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.length();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0] && ifWordExist(board,i,j,0,m,n,word,len))
                return true;
            }
        }
        return false;
    }
};