class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int r)
    {
        int n=mid-l+1;
        int m=r-mid;
        vector<int>nj(n),mj(m);
        for(int i=0;i<n;i++)
          nj[i]=nums[l+i];
        for(int i=0;i<m;i++)
          mj[i]=nums[mid+1+i];
        int i=0,j=0,k=l;
        while(i<n && j<m)
        {
            if(nj[i]<mj[j])
             nums[k++]=nj[i++];
            else
             nums[k++]=mj[j++];
        }
        while(i<n)
          nums[k++]=nj[i++];
        while(j<m)
          nums[k++]=mj[j++];
    }
    void mergesort(vector<int>&nums,int l,int r)
    {
        if(l<r)
        {
         int mid=l+(r-l)/2;
         mergesort(nums,l,mid);
         mergesort(nums,mid+1,r);
         merge(nums,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};