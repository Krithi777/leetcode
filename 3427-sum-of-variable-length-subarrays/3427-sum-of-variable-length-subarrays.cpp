class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int>sum(nums.size());
        int ans=0;
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
          sum[i]=sum[i-1]+nums[i];
        for(int i=0;i<nums.size();i++)
        {
            int l=max(0,i-nums[i]);
            if(l==0)
             ans+=sum[i];
            else
             ans+=sum[i]-sum[l-1];
        }
        return ans;
    }
};