class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<vector<int>>& heights,vector<vector<int>>&visited,int i,int j)
    {
       int dx[]={-1,1,0,0};
       int dy[]={0,0,-1,1};
       //you are finding cell that can be visited from edge and finds the cells that overlap 
       if(visited[i][j]==1)
          return;
       visited[i][j]=1;
       for(int k=0;k<4;k++)
       {
          if(i+dx[k]>=0 && i+dx[k]<heights.size() && j+dy[k]>=0 && j+dy[k]<heights[0].size())
          {
             if(heights[i][j]<=heights[i+dx[k]][j+dy[k]])
             {
                dfs(heights,visited,i+dx[k],j+dy[k]);
             }
          }
       }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>visitedpacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>visitedatlantic(heights.size(),vector<int>(heights[0].size(),0));
        for(int i=0;i<heights.size();i++)
        {
            dfs(heights,visitedpacific,i,0);
            dfs(heights,visitedatlantic,i,heights[0].size()-1);
        }
        for(int j=0;j<heights[0].size();j++)
        {
            dfs(heights,visitedpacific,0,j);
            dfs(heights,visitedatlantic,heights.size()-1,j);
        }
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[i].size();j++)
            {
                if(visitedpacific[i][j] && visitedatlantic[i][j])
                {
                    vector<int>r(2,0);
                    r[0]=i;
                    r[1]=j;
                    res.push_back(r);
                }
            }
        }
        return res;
    }
};