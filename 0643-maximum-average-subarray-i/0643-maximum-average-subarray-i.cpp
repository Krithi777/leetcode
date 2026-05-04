class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double m=0,s=0;
		for(int p=0;p<=k-1;p++)
			m+=nums[p];
        m=m;
		s=m;
		int i=1,j=k;
		while(j<nums.size())
		{
			s=s-nums[i-1]+nums[j];
			if(m<s)
				m=s;
			i++;
			j++;
		}
		return m/k;
    }
};