class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        p.push({0,k});
        while(!p.empty())
        {
            pair<int,int>i=p.top();
            p.pop();
            int u=i.second;
            int val=i.first;
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
        int m=INT_MIN;
        for(int i=1;i<=n;i++)
           m=max(m,dist[i]);
        if(m==INT_MAX)
          return -1;
        return m;
    }
};