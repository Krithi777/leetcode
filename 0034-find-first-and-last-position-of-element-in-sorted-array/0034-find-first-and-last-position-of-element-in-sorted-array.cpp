class Solution {
public:
    int bs(vector<int>&nums,int target,int l,int h)
    {
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                h=mid-1;
            else 
                return mid;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int i,j,m;
        m=bs(nums,target,0,nums.size()-1);
        if(m==-1)
           return ans;
        i=m;
        j=m;
        while(m!=-1)
        {
          i=m;
          m=bs(nums,target,0,m-1);
        }
        m=j;
        while(m!=-1)
        {
          j=m;
          m=bs(nums,target,m+1,nums.size()-1);
        }
        ans[0]=i;
        ans[1]=j;
        return ans;
    }
};