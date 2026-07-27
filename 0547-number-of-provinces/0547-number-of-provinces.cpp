class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        if(parent[x]==x)
          return x;
        return find(parent[x]);
    }
    void funcunion(int x,int y)
    {
        int ra=find(x);
        int rb=find(y);
        if(ra!=rb)
           parent[rb]=ra;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        parent=vector<int>(isConnected[0].size());
        unordered_set<int>s;
        for(int i=0;i<parent.size();i++)
           parent[i]=i;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1)
                   funcunion(i,j); 
            }
        }
        for(int i=0;i<parent.size();i++)
        {
            int k=find(i);
            if(!s.count(k))
                s.insert(k);
        }
        return s.size();
    }
};