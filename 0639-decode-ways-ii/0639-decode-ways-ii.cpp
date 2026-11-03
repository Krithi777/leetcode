class Solution {
public:
    int singlecount(char c)
    {
        if(c=='0')
           return 0;
        else if(c>='1' && c<='9')
           return 1;
        else if(c=='*')
           return 9;
        return 0;
    } 
    int paircount(char p,char c)
    {
        if(c=='0' && (p=='1'|| p=='2'))
           return 1;
        else if(c=='0' && p=='*')
           return 2;
        else if(c=='*' && p=='1')
           return 9;
        else if(c=='*' && p=='2')
           return 6;
        else if(c=='*' && p=='*')
           return 15;
        else if((c>='1' && c<='9') && p=='1')
           return 1;
        else if((c>='1' && c<='6') && p=='2')
           return 1;
        else if((c>='7' && c<='9') && p=='*')
           return 1;
        else if((c>='1' && c<='6') && p=='*')
           return 2;      
        return 0;
    }
    int numDecodings(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long>dp(s.size()+1,0);
        if(s[0]=='0')
           return 0;
        dp[0]=1;
        if(s[0]=='*')
          dp[1]=9;
        else 
          dp[1]=1;
        for(int i=1;i<s.size();i++)
        {
            int j=i+1;
            dp[j]=(singlecount(s[i])*dp[j-1]+paircount(s[i-1],s[i])*dp[j-2])%MOD;
        }
        return dp[s.size()];
    }
};