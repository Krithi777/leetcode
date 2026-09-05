class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]);//yesterday no stock or yesterdays cooldown so no stock
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);//yesterday stock available or buy stock today
            dp[i][2]=dp[i-1][1]+prices[i];//yeseterday stock avilable so sell and enter cooldown
        }
        int m=max(dp[n-1][0],dp[n-1][1]);
        return max(m,dp[n-1][2]);    
    }
};