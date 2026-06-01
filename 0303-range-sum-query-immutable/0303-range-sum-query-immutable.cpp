class NumArray {
public:
    vector<int>sum;
    NumArray(vector<int>& nums) {
        vector<int>sum(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
           sum[i]=sum[i-1]+nums[i];
        } 
        this->sum=sum;
    }
    int sumRange(int left, int right) {
        if(left==0)
          return this->sum[right];
        return this->sum[right]-this->sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */