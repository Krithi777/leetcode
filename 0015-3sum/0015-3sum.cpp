class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();)
        {
            if(nums[i]>0)
              break;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                int check=-nums[i];
                if(nums[j]+nums[k]==check)
                {
                    vector<int>res;
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[k]);
                    m.push_back(res);
                    int n=nums[j];
                    int p=nums[k];
                    while(j<nums.size() && nums[j]==n)
                       j++;
                    while(k>=0 && nums[k]==p)
                       k--;
                } 
                else if(nums[j]+nums[k]>check)
                  k--;
                else
                  j++; 
            }
            int q=nums[i];
            while(i<nums.size() && nums[i]==q)
              i++;
        }
        return m;
    }
};