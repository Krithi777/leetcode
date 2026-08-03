class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        if(parent[x]==x)
          return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void unionfunc(int a,int b)
    {
        int ra=find(a);
        int rb=find(b);
        if(ra!=rb)
          parent[rb]=ra;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent=vector<int>(n);
        for(int i=0;i<parent.size();i++)
          parent[i]=i;
        for(int i=0;i<edges.size();i++)
        {
            int j=edges[i][0];
            int k=edges[i][1];
            unionfunc(j,k);
        }
        if(find(source)==find(destination))
           return true;
        return false;
    }
};