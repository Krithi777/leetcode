struct cmp
{
    bool operator()(const pair<int,string>&a,const pair<int,string>&b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>p;
        vector<string>res;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        for(auto i:m)
        {
            p.push({i.second,i.first});
        }
        while(k>0)
        {
            res.push_back(p.top().second);
            p.pop();
            k--;
        }
        return res;
    }
};