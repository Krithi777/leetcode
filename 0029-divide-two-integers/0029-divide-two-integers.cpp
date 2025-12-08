class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
           return INT_MAX;
        long long d1=abs((long long)dividend);
        long long d2=abs((long long)divisor);
        bool n=(dividend<0)^(divisor<0);
        long long q=0;
        while(d1>=d2)
        {
            long long t=d2,m=1;
            while(d1>=(t<<1))
            {
                t<<=1;
                m<<=1;
            }
            d1-=t;
            q+=m;
        }
        return n?-q:q;
    }
};