class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>p;
        for(int i=0;i<stones.size();i++)
            p.push(stones[i]);
        while(p.size()>=2)
        {
            int x=p.top();
            p.pop();
            int y=p.top();
            p.pop();
            if(x!=y)
              p.push(x-y);
        }
        if(p.size()>0)
          return p.top();
        return 0;
    }
};