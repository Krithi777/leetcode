class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        vector<int>b;
        for(int i=0;i<nums1.size();i++)
        {
           v.push_back(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++)
        {
            v.push_back(nums2[j]);
        }
        sort(v.begin(),v.end());
        if((nums1.size()+nums2.size())%2==0)
        {
            int s=v[(nums1.size()+nums2.size())/2]+v[(nums1.size()+nums2.size())/2-1];
            return (s/(double)2);
        }
        else
        {
          return (double)(v[(nums1.size()+nums2.size())/2]);
        }  
    }
};