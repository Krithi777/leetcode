class Solution {
public:
    vector<string>ans;
    void generate(int open,int close,string &curr,int n)
    {
        if(open==n && close==n)
        {
           ans.push_back(curr);
           return;
        }
        if(open<n)
        {
           curr.push_back('(');
           generate(open+1,close,curr,n);
           curr.pop_back();
        }
        if(close<open)
        {
            curr.push_back(')');
            generate(open,close+1,curr,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="(";
        generate(1,0,curr,n);
        return ans;
    }
};