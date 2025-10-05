class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m=nums.size();
        vector<int> res;
        for(int i=0;i<m-1;i++)
        {
             for(int j=i+1;j<m;j++)
             {
                int s=nums[i]+nums[j];
                if(s==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
             }
        }
        return res;
    }
};