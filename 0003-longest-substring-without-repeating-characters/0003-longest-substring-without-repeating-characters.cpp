class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1)
           return s.size();
        int i=0,j=1,l=0;
        unordered_set<int>m;
        m.insert(s[i]);
        while(j<s.size())
        {
           if(m.count(s[j]))
           {
             while(m.count(s[j]))
             {
               m.erase(s[i]);
               i++;
             }
           }
           m.insert(s[j]);
           j++;
           l=max(l,j-i);
        }
        return l;
    }
};