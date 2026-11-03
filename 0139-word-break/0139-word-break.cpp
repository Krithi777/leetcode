class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<bool>dp(s.size()+1,false);
        for(int i=0;i<wordDict.size();i++)
             st.insert(wordDict[i]);
        dp[0]=true;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(dp[j]==true)
                {
                    string val=s.substr(j,i-j+1);
                    if(st.count(val))
                    {
                        dp[i+1]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};