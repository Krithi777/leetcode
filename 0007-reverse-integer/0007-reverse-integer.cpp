class Solution {
public:
    int reverse(int x) {
        long s=0;
        while(x!=0)
        {
            int b=x%10;
            s=s*10+b;
            x/=10;
        }
        if(s<-pow(2,31) || s>(pow(2,31)-1))
          return 0;
        return s;
    }
};