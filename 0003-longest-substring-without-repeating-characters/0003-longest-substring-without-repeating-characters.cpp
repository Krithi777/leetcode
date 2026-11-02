class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>m;
        if(s.size()==1 || s.size()==0)
           return s.size();
        int i=0,j=1;
        m.insert(s[i]);
        int count=0;
        while(i<s.size() && j<s.size())
        {
            while(m.count(s[j]))
            {
                m.erase(s[i]);
                i++;
            }
            m.insert(s[j]);
            count=max(count,j-i+1);
            j++;
        }
        return count;
    }
};