class Solution {
public:
    int binsearch(vector<int>& days,int x,int l,int h)
    {
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(days[mid]>=x)
              h=mid-1;
            else 
              l=mid+1;
        }
        return l;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size());
        dp[0]=min(costs[0],costs[1]);
        dp[0]=min(dp[0],costs[2]);
        for(int i=1;i<days.size();i++)
        {
            int day7=INT_MAX,day30=INT_MAX;
            int n=binsearch(days,days[i]-6,0,i);
            if(n==0)
             day7=costs[1];
            else
             day7=dp[n-1]+costs[1];
            int m=binsearch(days,days[i]-29,0,i);
            if(m==0)
             day30=costs[2];
            else 
             day30=dp[m-1]+costs[2];
            dp[i]=min(dp[i-1]+costs[0],day7);
            dp[i]=min(dp[i],day30);
        }
        return dp[days.size()-1];
    }
};