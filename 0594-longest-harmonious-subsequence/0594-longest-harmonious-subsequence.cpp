class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
          m[nums[i]]++;
        int maxi=INT_MIN;
        for(auto i:m)
        {
            int key=i.first;
            if(m.count(key+1))
                maxi=max(m[key+1]+i.second,maxi);
        }
        if(maxi==INT_MIN)
          return 0;
        return maxi;
    }
};