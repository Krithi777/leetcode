class Solution {
public:
    int arrangeCoins(int n) {
        int s=n;
        for(int i=1;i<=n;i++)
        {
            s-=i;
            if(s<0)
              return i-1;
            if(s==0)
              return i;
        }
        return 0;
    }
};