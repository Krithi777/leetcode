class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
           m[stones[i]]=i;
        if(m.find(1)!=m.end())
          dp[1][1]=true;
        for(int i=0;i<n;i++)
        {
            for(int k=1;k<dp[i].size();k++)
            {
                if(dp[i][k]==true)
                {
                    if(m.find(stones[i] + k) != m.end())
                    {
                        dp[m[stones[i] + k]][k]=true;
                    }
                    if(m.find(stones[i] + k+1) != m.end())
                    {
                            dp[m[stones[i] + k+1]][k+1]=true;
                    }
                    if(k==1)
                    continue;
                    if(m.find(stones[i] + k-1) != m.end())
                    {
                            dp[m[stones[i] + k-1]][k-1]=true;
                    }
                }
            }        
        }
        for(int k=1;k<n;k++)
        {
            if(dp[n-1][k]==true)
               return true;
        }
        return false;
    }
};