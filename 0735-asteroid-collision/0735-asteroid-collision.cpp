class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        stack<int>s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]<0)
            {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i]))
                    s.pop();
                if(!s.empty() && s.top()>abs(asteroids[i]))
                    continue;
                else if(!s.empty() && s.top()==abs(asteroids[i]))
                {
                    s.pop();
                    continue;
                }
            }
            s.push(asteroids[i]);
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};