class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>s;
        s.push(nums[0]);
        vector<long long>res;
        for(int i=1;i<nums.size();i++)
        {
            if(!s.empty() && s.top()==nums[i])
            {
              long long k=nums[i];
              while(!s.empty() && s.top()==k)
              {
                k=s.top()+s.top();
                s.pop();
              }
              s.push(k);              
            }
            else
             s.push(nums[i]);
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};