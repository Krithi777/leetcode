class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int s=0;
       int count=0;
       unordered_map<int,int>m;
       m[0]=1;
       for(int i=0;i<nums.size();i++)
       {
          s=s+nums[i];
          count+=m[s-k];
          m[s]++;
       }
       return count;
    }
};