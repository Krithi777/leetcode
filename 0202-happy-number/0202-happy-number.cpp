class Solution {
public:
    int nextnum(int n)
    {
        int s=0;
        while(n!=0)
        {
            int  b=n%10;
            s=s+pow(b,2);
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        while(n!=1 && n!=4)
        {
            n=nextnum(n);
        }
        return n==1;
    }
};