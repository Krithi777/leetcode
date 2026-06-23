class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        unordered_map<int,int>m;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto i:m)
        {
            int n=i.first;
            int f=i.second;
            p.push({f,n});
            if(p.size()>k)
              p.pop();
        }
        while(p.size()>0)
        {
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};