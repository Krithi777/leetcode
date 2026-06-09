class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(!st.empty() && s[i]==st.top())
              st.pop();
            else
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