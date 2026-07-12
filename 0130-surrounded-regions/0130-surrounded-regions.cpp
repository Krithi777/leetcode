class Solution {
public:
    int row,col;
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(i>=0 && i<row && j>=0 && j<col && board[i][j]=='O')//find connected ones
        {
            board[i][j]='S';
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
    void solve(vector<vector<char>>& board) {
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;i++)//border traversal
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][col-1]=='O')
                dfs(board,i,col-1);
        }
        for(int i=0;i<col;i++)//border traversal
        {
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[row-1][i]=='O')
                dfs(board,row-1,i);
        }
        for(int i=0;i<row;i++)//changing the correct ones
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O')
                   board[i][j]='X';
                if(board[i][j]=='S')
                   board[i][j]='O';
            }
        }
    }
};