class Solution {
public:
    vector<vector<bool>>visited;
    int row,col;
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i>=0 && i<row && j>=0 && j<col  && !visited[i][j] && grid[i][j]!='0')
        {
            visited[i][j]=true;
            dfs(grid,i-1,j);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);
            dfs(grid,i,j+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        row=grid.size();
        col=grid[0].size();
        visited=vector<vector<bool>>(row,vector<bool>(col, false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i][j] && grid[i][j]!='0')
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};