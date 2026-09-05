class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),false);
        dp[0]=true;
        int val=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i<=val)
            {
                dp[i]=true;
                val=max(val,i+nums[i]);
            }
        }
        return dp[nums.size()-1];
    }
};