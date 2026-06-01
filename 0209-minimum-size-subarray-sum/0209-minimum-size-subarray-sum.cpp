class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,s=0,m=INT_MAX;
        while(j<nums.size())
        {
            s+=nums[j];
            while(s>=target)
            {
                m=min(m,j-i+1);
                s-=nums[i];
                i++;
            }
            j++;
        }
        if(m==INT_MAX)
          return 0;
        return m;
    }
};