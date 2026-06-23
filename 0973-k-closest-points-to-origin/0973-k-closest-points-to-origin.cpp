class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,int>>p;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int d=((x*x)+(y*y));
            p.push({d,i});
            if(p.size()>k)
              p.pop();
        }
        while(p.size()>0)
        {
            res.push_back(points[p.top().second]);
            p.pop();
        }
        return res;
    }
};