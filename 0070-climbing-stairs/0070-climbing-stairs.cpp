class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
         return 1;
        else if(n==2)
        return 2;
        else
        {
            int temp=0,a=1,b=2;
            for(int k=3;k<=n;k++)
            {
             temp=a+b;
             a=b;
             b=temp;
            }
            return temp;         
        }
    }
};