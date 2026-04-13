class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> p;
        for (int i=0;i<nums.size();i++)
            p[nums[i]]++;
        for(auto i:p)
        {
            if(i.second>1)
              return true;
        }
        return false;
    }
};