class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>p;
        vector<vector<int>>res;
        set<pair<int,int>>s;
        p.push({nums1[0]+nums2[0],0,0});
        s.insert({0,0});
        while(k>0)
        {
            int i=get<1>(p.top());
            int j=get<2>(p.top());
            p.pop();
            vector<int>m;
            m.push_back(nums1[i]);
            m.push_back(nums2[j]);
            res.push_back(m);

            if(i+1<nums1.size() && !s.count({i+1,j}))
            {
              p.push({nums1[i+1]+nums2[j],i+1,j});
              s.insert({i+1,j});
            }
            if(j+1<nums2.size() && !s.count({i,j+1}))
            {
              p.push({nums1[i]+nums2[j+1],i,j+1});
              s.insert({i,j+1});
            }
            k--;
        }
        return res;
    }
};