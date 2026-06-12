class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>p;
        stack<char>q;
        for(int i=0;i<s.size();i++)
        {
            if(!p.empty() && s[i]=='#')
               p.pop();
            else if(p.empty() && s[i]=='#')
               continue;
            else
               p.push(s[i]);
        }
        for(int i=0;i<t.size();i++)
        {
            if(!q.empty() && t[i]=='#')
               q.pop();
            else if(q.empty() && t[i]=='#')
               continue;
            else
               q.push(t[i]);
        }
        while(!p.empty() && !q.empty())
        {
            if(p.top()!=q.top())
              return false;
            p.pop();
            q.pop();
        }
        if(p.empty() && q.empty()) 
           return true;
        return false;
    }
};