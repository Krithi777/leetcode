class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s,p;
        for(int i=0;i<path.size();)
        {
            string k="";
            if(path[i]=='/')
            {
                i++;
                if(i<path.size())
                {
                    while(i<path.size() && path[i]!='/')
                    {
                        k+=path[i];
                        i++;
                    }
                    if(k==".")
                    continue;
                    else if(!s.empty() && k=="..")
                        s.pop();
                    else if(k!="" && k!="..")
                    s.push("/"+k);
                }
            }
        }
        if(s.empty())
            return "/";
        string res="";
        while(!s.empty())
        {
           p.push(s.top());
           s.pop();
        }
        while(!p.empty())
        {
            res+=p.top();
            p.pop();
        }
        return res;
    }
};