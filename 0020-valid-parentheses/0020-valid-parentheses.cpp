class Solution {
public:
    bool isValid(string p) {
        stack<char>s;
        for(char c: p)
        {
            if(c=='(' || c=='{' || c=='[')
              s.push(c);
            else
            {
                if(s.empty())
                  return false;
                char d=s.top();
                if(c==')' && d!='(' || c=='}' && d!='{'  || c==']' && d!='[' )
                {
                        return false;
                }
                s.pop();
            }
        }        
        return  s.empty();
    }
};