class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int val;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int a,b;
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                if(tokens[i]=="+") s.push(a+b);
                else if(tokens[i]=="-") s.push(b-a);
                else if(tokens[i]=="*") s.push(a*b);
                else if(tokens[i]=="/") s.push(b/a);
            }
            else
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};