class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(int i=0;i<nums.size();i++)
            tot+=nums[i];  
        if(tot%2!=0)
           return false;
        vector<bool>dp(tot+1,false);
        dp[0]=true;
        int t=tot/2;
        for(int i=0;i<nums.size();i++)
        {
            for(int x=t;x>=0;x--)
            {
                if(dp[x]==true)
                    dp[x+nums[i]]=true;
            }   
        }
        return dp[t];
    }
};