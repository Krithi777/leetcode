class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        long int k=0;
        while(x!=0)
        {
            int b=x%10;
            k=k*10+b;
            x=x/10;
        }
        if(y==k && y>=0)
          return true;
        return false;
    }
};