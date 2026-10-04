class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,float>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            float w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<float>dist(n,INT_MIN);
        dist[start_node]=1;
        priority_queue<pair<float,int>>p;
        p.push({1,start_node});
        while(!p.empty())
        {
            pair<float,int>i=p.top();
            p.pop();
            int u=i.second;
            float val=i.first;
            for(auto j:adj[u])
            {
                int v=j.first;
                float w=j.second;
                if(val*w>dist[v])
                {
                   dist[v]=val*w;
                   p.push({dist[v],v});
                }
            }
        }
        if(dist[end_node]==INT_MIN)
          return 0;
        return dist[end_node];
    }
};