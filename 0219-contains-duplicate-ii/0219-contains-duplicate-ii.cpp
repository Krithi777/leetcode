class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=1;
        unordered_map<int,int>m;
        m[nums[i]]=i;
        while(j<nums.size())
        {
            if(m.count(nums[j]))
            {
                i=m[nums[j]];
                if(j-i<=k)
                  return true;
            }
            m[nums[j]]=j;
            j++;
        }
        return false;
    }
};