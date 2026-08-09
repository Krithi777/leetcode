class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>maxdp(nums.size(),0);
        vector<int>mindp(nums.size(),0);
        maxdp[0]=nums[0];
        mindp[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int m=max(maxdp[i-1]*nums[i],nums[i]);//maximum till now or new subarray
            m=max(m,mindp[i-1]*nums[i]);
            maxdp[i]=m;

            int n=min(maxdp[i-1]*nums[i],nums[i]);//minimum till now or new subarray
            n=min(n,mindp[i-1]*nums[i]);
            mindp[i]=n;

            res=max(res,m);
        }
        return res;
    }
};