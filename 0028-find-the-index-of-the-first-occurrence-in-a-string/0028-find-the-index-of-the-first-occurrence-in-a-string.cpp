class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0;
        int i=0;
        if(haystack.length()<needle.length())
            return -1;
        while(i<haystack.length())
        {
            if(haystack[i]==needle[j])
            {
                while(j<needle.length())
                {
                    if(haystack[i+j]!=needle[j])
                       break;
                    ++j;
                }
                if(j==needle.length())
                   return i;
                j=0;
            }
            i++;
        }
        return -1;
    }
};