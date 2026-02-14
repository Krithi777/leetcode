class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int s=0;
        while(i<j)
        {
            int w=min(height[i],height[j])*(j-i);
            s=max(s,w);
            if(height[i]<height[j])
               i++;
            else
               j--;
        }
        return s;
    }
};