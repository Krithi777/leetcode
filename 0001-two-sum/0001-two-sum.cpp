class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
             m[nums[i]]=i;
        vector<int>res(2,0);
        for(int i=0;i<nums.size();i++)
        {
            int val=target-nums[i];
            if(m.count(val) && m[val]!=i)
            {
                res[0]=i;
                res[1]=m[val];
                return res;
            }
        }
        return res;
    }
};