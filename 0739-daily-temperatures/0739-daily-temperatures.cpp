class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        s.push(temperatures.size()-1);
        vector<int>res(temperatures.size(),0);
        for(int i=temperatures.size()-2;i>=0;i--)
        {
            while(!s.empty() && temperatures[s.top()]<=temperatures[i])
            {
                s.pop();
            }
            if(!s.empty())
               res[i]=s.top()-i;
            s.push(i);
        }
        return res;
    }
};