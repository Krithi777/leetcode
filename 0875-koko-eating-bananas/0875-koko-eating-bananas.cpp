class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            high=max(high,piles[i]);
        }
        int val=high;
        while(low<=high)
        {
            int k=low+(high-low)/2;
            int hour=0;
            for(int i=0;i<piles.size();i++)
            {
                if(hour>h)
                  break;
                if(piles[i]<=k)
                 hour++;
                else
                 hour+=(piles[i]+k-1)/k;
            }
            if(hour<=h)
            {
               val=min(val,k);
               high=k-1;
            }
            if(hour>h)
                low=k+1;
        }
        return val;
    }
};