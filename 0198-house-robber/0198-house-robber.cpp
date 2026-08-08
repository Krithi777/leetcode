class Solution {
public:
    int rob(vector<int>& arr) {
      int n=arr.size();
        vector<int>dp(n,0);
        if(arr.size()==1)
           return arr[0];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return max(dp[n-1],dp[n-2]);  
    }
};