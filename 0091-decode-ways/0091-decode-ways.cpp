class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,0);
        if(s[0]=='0')
           return 0;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<dp.size();i++)
        {
            int j=i-1;
            int k=(s[j-1]-'0')*10+(s[j]-'0');
            int val=0;
            if(s[j]<='9' && s[j]>='1')
               val+=dp[i-1];
            if(k>=10 && k<=26)
               val+=dp[i-2];
            dp[i]=val;
        }
        return dp[s.size()];
    }
};