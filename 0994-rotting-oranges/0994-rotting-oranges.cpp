class Solution {
public:
    queue<pair<int,int>>q;
    int row,col;
    int bfs(vector<vector<int>>& grid,int fresh)
    {
        int count=-1;
        while(!q.empty())
        {
            int size=q.size();
            while(size!=0)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(fresh!=0)
                {
                    if(i-1>=0 && i-1<row && j>=0 && j<col && grid[i-1][j]==1)
                    {
                        q.push({i-1,j});
                        grid[i-1][j]=2;
                         fresh--;
                    }
                    if(i+1>=0 && i+1<row && j>=0 && j<col && grid[i+1][j]==1)
                    {
                        q.push({i+1,j});
                        grid[i+1][j]=2;
                         fresh--;
                    }
                    if(i>=0 && i<row && j-1>=0 && j-1<col && grid[i][j-1]==1)
                    {
                        q.push({i,j-1});
                        grid[i][j-1]=2;
                         fresh--;
                    }
                    if(i>=0 && i<row && j+1>=0 && j+1<col && grid[i][j+1]==1)
                    {
                        q.push({i,j+1});
                        grid[i][j+1]=2;
                         fresh--;
                    } 
                }                   
                size--;
            }
            count++;
        }
        if(fresh!=0)
          return -1;
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        row=grid.size();
        col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                  fresh++;
                if(grid[i][j]==2)
                  q.push({i,j});
            }
        }
        if(fresh==0)
          return 0;
        if(!q.empty())
          return bfs(grid,fresh);
        return -1;
    }
};