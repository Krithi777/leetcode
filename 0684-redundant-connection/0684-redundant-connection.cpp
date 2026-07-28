class Solution {
public:
    vector<int>parent;
    vector<int>res;
    int find(int x)
    {
        if(parent[x]==x)
          return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void funcunion(int x,int y)
    {
        int ra=find(x);
        int rb=find(y);
        if(ra==rb)
        {
         res[0]=x;
         res[1]=y;
        }
        else
          parent[rb]=ra;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent=vector<int>(edges.size()+1);
        res=vector<int>(2,0);
        for(int i=0;i<parent.size();i++)
           parent[i]=i;
        for(int i=0;i<edges.size();i++)
        {
            int j=edges[i][0];
            int k=edges[i][1];
            funcunion(j,k);
        }
        return res;
    }
};