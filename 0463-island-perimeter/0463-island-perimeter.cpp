class Solution {
public:
    int row,col;
    int  count=0;
    vector<vector<bool>>visited;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=0 && i<row && j>=0 && j<col && !visited[i][j] && grid[i][j]==1)
        {
            visited[i][j]=true;
            int m[4]={-1,1,0,0};
            int n[4]={0,0,-1,1};
            for(int k=0;k<4;k++)
            {
                int r=i+m[k];
                int c=j+n[k];
                if(r<0 || r>=row || c<0 || c>=col)
                {
                    count++;
                }
                else if(grid[r][c]==0)
                {
                    count++;
                }
                else
                {
                    dfs(grid,r,c);
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        visited=vector<vector<bool>>(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                    dfs(grid,i,j);
            }
        }
        return count;
    }
};