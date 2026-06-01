class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count=0;
        int cur=0;
        for(int i=0;i<nums.size();i++)
        {
            cur=cur+nums[i];
            if(cur==0)
             count++;
        }
        return count;
    }
};