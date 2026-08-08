class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(arr.size(),0);
        if(n==1)
          return arr[0];
        if(n==2)
          return max(arr[0],arr[1]);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n-1;i++)//0-(n-2)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        int val=dp[n-2];
        dp=vector<int>(n+1,0);
        dp[1]=arr[1];
        dp[2]=max(arr[1],arr[2]);
        for(int i=3;i<n;i++)//1-(n-1)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return max(dp[n-1],val);
    }
};