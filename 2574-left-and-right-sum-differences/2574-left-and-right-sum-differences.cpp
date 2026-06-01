class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l=0,s=0;
        int r;
        for(int i=0;i<nums.size();i++)
          s+=nums[i];
        vector<int>a(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            r=s-l-nums[i];
            a[i]=abs(l-r);
            l+=nums[i];
        }
        return a;
    }
};