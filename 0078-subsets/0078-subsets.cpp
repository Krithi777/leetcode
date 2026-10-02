class Solution {
public:
    vector<vector<int>>ans;
    void generate(int index,vector<int>&curr,vector<int>&nums)
    {
        ans.push_back(curr);

        if(index==nums.size())
           return;

        for(int i=index;i<nums.size();i++)
        {
         curr.push_back(nums[i]);
         generate(i+1,curr,nums);
         curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        generate(0,curr,nums);
        return ans;
    }
};