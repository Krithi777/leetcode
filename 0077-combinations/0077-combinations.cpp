class Solution {
public:
    vector<vector<int>>ans;
    void generate(int index,vector<int>& curr,int n,int k)
    {
        if(curr.size()==k)
        {
          ans.push_back(curr);
          return;
        }
      
        for(int i=index;i<=n;i++)
        {
            curr.push_back(i);
            generate(i+1,curr,n,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        generate(1,curr,n,k);
        return ans;
    }
};