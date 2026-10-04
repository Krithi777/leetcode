class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int maxcount=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++)
        {
          vector<int>dist(n,INT_MAX);
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
          dist[i]=0;
          p.push({0,i});
          while(!p.empty())
          {
            pair<int,int>n=p.top();
            p.pop();
            int u=n.second;
            int val=n.first;
            for(auto j:adj[u])
            {
                int v=j.first;
                int w=j.second;
                if(val+w<dist[v])
                {
                    dist[v]=val+w;
                    p.push({dist[v],v});
                }
            }
          }
          int count=0;
          for(int k=0;k<n;k++)
          {
            if(dist[k]<=distanceThreshold)
              count++;
          }
          if(count<=maxcount)
          {
             maxcount=count;
             city=i;
          }
        }
        return city;
    }
};