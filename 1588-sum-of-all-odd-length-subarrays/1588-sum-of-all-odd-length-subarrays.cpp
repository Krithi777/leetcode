class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int>sum(arr.size());
        int ans=arr[0];
        sum[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
          sum[i]=sum[i-1]+arr[i];
          ans+=arr[i];
        }
        if(arr.size()<3)
          return ans;
        for(int k=2;k<arr.size();k=k+2)
        {
            for(int j=0;j+k<arr.size();j++)
            {
                if(j==0)
                 ans+=sum[k];
                else
                 ans+=sum[k+j]-sum[j-1];
            }
        }
        return ans;
    }
};