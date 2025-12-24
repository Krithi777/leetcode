class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<2)
           return false;
        int d=sqrt(num);
        int c=1;
        for(int i=2;i<=d;i++)
        {
            if(num%i==0)
            {
               c+=i;
               if(i!=num/i)
               {
                c+=num/i;
               }
            }       
        }
        return c==num;
    }
};