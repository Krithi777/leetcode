class Solution {
public:
    bool isValid(string s) {
        stack<char>p;
        for(char c:s)
        {
            if(c=='(' || c=='[' || c=='{')
              p.push(c);
            else if(c==')' || c==']' || c=='}')
            {
               char j='(';
               j=(c==']')?'[':j;
               j=(c=='}')?'{':j;
               if(!p.empty() && p.top()==j)
                  p.pop();
               else
                  return false;
            }
            
        }
        if(!p.empty())
          return false;
        return true;
    }
};