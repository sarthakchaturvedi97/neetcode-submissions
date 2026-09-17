class Solution {
public:
    struct Node{
        Node* ch[26] = {};
        string* word = NULL; 
    };
    int m,n;
    vector<string> result;
    void dfs(vector<vector<char>>& board, int i, int j, Node* node)
    {
        if(i<0 ||i>=m || j<0 || j>=n || board[i][j] == '#')
        return;

        char c = board[i][j];
        if(!node->ch[c-'a'])
        return;
        
        node = node->ch[c-'a'];
        if(node->word)
        {
            result.push_back(*node->word);
            node->word = NULL;
        }

        board[i][j] = '#';
        dfs(board,i+1,j,node);
        dfs(board,i-1,j,node);
        dfs(board,i,j+1,node);
        dfs(board,i,j-1,node);
        board[i][j] = c;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        Node *root = new Node();
        for(auto &w: words)
        {
            Node* node = root;
            for(char c: w)
            {
                if(!node->ch[c-'a'])
                node->ch[c-'a'] = new Node();

                node = node->ch[c-'a']; 
            }
            node->word = &w;
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            dfs(board,i,j,root);
        }
        return result;
    }
};