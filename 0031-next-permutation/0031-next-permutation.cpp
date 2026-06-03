class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                int j=nums.size()-1;
                while(nums[i]>=nums[j])
                   j--;
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(i==-1)
            reverse(nums.begin(),nums.end());
    }
};