class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>m;
        int k=*max_element(nums.begin(),nums.end());
        vector<int>dp(k+1,0);
        for(int i=0;i<nums.size();i++)
             m[nums[i]]+=nums[i];
        if(m.count(0))
            dp[0]=m[0];
        if(m.count(1))
            dp[1]=max(dp[0],m[1]);
        for(int i=2;i<dp.size();i++)
        {
            dp[i]=max(dp[i-2]+m[i],dp[i-1]);
        }
        return dp[dp.size()-1];
    }
};