class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int val=1;//minimum steps 
        int cur=nums[0];//current range (k remains same until this changes)
        int far=nums[0];//farthest reachable point
        for(int i=1;i<nums.size();i++)
        {
            if(i<=far)
            {
                dp[i]=val;
                if(i+nums[i]>far)
                  far=i+nums[i];
                if(i==cur)
                {
                    cur=far;
                    val=dp[i]+1;
                }
            }
        }
        return dp[nums.size()-1];
    }
};