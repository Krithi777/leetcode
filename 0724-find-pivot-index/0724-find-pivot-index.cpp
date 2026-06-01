class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>sum(nums.size());
        int n=nums.size();
        sum[0]=nums[0];
        for(int i=1;i<n;i++)
           sum[i]=sum[i-1]+nums[i];
        if(sum[n-1]-sum[0]==0)
              return 0;
        for(int i=1;i<n;i++)
        {
            if(sum[i-1]==sum[n-1]-sum[i])
              return i;
        }
        return -1;
    }
};