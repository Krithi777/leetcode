class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1000000007;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,0)));
        for(int k=1;k<=maxMove;k++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    long long count = 0;
                    if(i - 1 < 0)
                        count =(count + 1) % MOD;
                    else
                        count =(count + dp[i - 1][j][k - 1]) % MOD;
                    if(j - 1 < 0)
                        count =(count + 1) % MOD;
                    else
                        count =(count + dp[i][j - 1][k - 1]) % MOD;
                    if(i + 1 >= m)
                        count = (count + 1) % MOD;
                    else
                        count =(count + dp[i + 1][j][k - 1]) % MOD;
                    if(j + 1 >= n)
                        count =(count + 1) % MOD;
                    else
                        count =(count + dp[i][j + 1][k - 1]) % MOD;
                    dp[i][j][k]=count;
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};