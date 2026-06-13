class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        int count=0;
        while(i>=0)
        {
            if(s[i]==' ') 
              i--;
            else
              break;
        }
        while(i>=0)
        {
            if(s[i]==' ')                
                break;
            count++;
            i--;
        }
        return count;
    }
};