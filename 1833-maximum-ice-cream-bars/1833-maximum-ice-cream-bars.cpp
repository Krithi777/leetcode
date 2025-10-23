class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int min=*min_element(costs.begin(),costs.end());
        int max=*max_element(costs.begin(),costs.end());
        vector<int>count(max-min+1,0);
        for(int a:costs)
          count[a-min]++;
        for(int i=1;i<count.size();i++)
          count[i]+=count[i-1];
        vector<int>out(costs.size());
        for(int i=costs.size()-1;i>=0;i--)
        {
            int num=costs[i];
            out[count[num-min]-1]=num;
            count[num-min]--;
        }
        int i,sum=0;
        for(i=0;i<out.size();i++)
        {
            sum+=out[i];
            if(sum>coins)
              break;
            if(sum==coins)
              return i+1;
        }
        return i;
    }
};