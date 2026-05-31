class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int m=INT_MAX;
        for(int k=l;k<=r;k++)
        {
            int s=0;
            for(int i=0;i<k;i++)
              s+=nums[i];
            if(s>0 && m>s)
                  m=s;
            for(int i=k;i<nums.size();i++)
            {
                s+=nums[i]-nums[i-k];
                if(s>0 && m>s)
                  m=s;
            }
        }
        if(m==INT_MAX)
          return -1;
        return m;
    }
};