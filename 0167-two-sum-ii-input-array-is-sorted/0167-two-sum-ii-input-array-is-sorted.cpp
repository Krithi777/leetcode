class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>m;
        int i=0,j=numbers.size()-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]==target)
            {
                m.push_back(i+1);
                m.push_back(j+1);
                break;
            }
            else if(numbers[i]+numbers[j]>target)
              j--;
            else
              i++;
        }
        return m;
    }
};