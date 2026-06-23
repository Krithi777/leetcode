class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>p;
        string res="";
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        for(auto i:m)
        {
            char c=i.first;
            int f=i.second;
            p.push({f,c});
        }
        while(p.size()>0)
        {
            int k=p.top().first;
            char c=p.top().second;
            while(k)
            {
                res+=c;
                k--;
            }
            p.pop();
        }
        return res;
    }
};