class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(isdigit(s[i]) && !st.empty())
            {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        string t="";
        while(!st.empty())
        {
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};