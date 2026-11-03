class Solution {
public:
    int singlecount(char c)
    {
        if(c=='0')
          return 0;
        else
          return 1;
    }
    int paircount(char c,char p)
    {
        if(c=='0' && (p=='1' || p=='2'))
           return 1;
        else if((c>='7' && c<='9') && p=='1')
           return 1;
        else if((c>='1' && c<='6') && ( p=='1' || p=='2'))
           return 1;
        return 0;
    }
    int numDecodings(string s) {
        vector<long long>dp(s.size()+1,0);
        if(s[0]=='0')
           return 0;
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<s.size();i++)
        {
            int j=i+1;
            dp[j]=singlecount(s[i])*dp[j-1]+paircount(s[i],s[i-1])*dp[j-2];
        }
        return dp[s.size()];
    }
};