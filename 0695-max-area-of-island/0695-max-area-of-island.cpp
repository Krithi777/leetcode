class Solution {
public:
    vector<vector<bool>>visited;
    int row,col;
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0 && i< row && j>=0 && j<col && !visited[i][j] && grid[i][j]!=0)
        {
            visited[i][j]=1;
            return dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1)+1;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=0;
        row=grid.size();
        col=grid[0].size();
        visited=vector<vector<bool>>(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i][j] && grid[i][j]!=0)
                    m=max(m,dfs(grid,i,j));
            }
        }
        return m;
    }
};