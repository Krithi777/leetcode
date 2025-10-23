class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int min=*min_element(heights.begin(),heights.end());
        int max=*max_element(heights.begin(),heights.end());
        vector<int>count(max-min+1,0);
        for(int a:heights)
           count[a-min]++;
        for(int i=1;i<count.size();i++)
           count[i]+=count[i-1];
        vector<int>out(heights.size());
        for(int i=heights.size()-1;i>=0;i--)
        {
            int num=heights[i];
            out[count[num-min]-1]=num;
            count[num-min]--;
        }
        int j=0;
        for(int i=0;i<heights.size();i++)
        {
            if(heights[i]!=out[i])
             j++;
        }
        return j;
    }
};