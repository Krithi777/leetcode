class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<=2)
           return fruits.size();
        int k=INT_MIN;
        int i=0,j=1;
        unordered_map<int,int>m;
        m[fruits[i]]++;
        while(j<fruits.size())
        {
            m[fruits[j]]++;
            if(m.size()>2)
            {
                while(m.size()>2)
                {
                    m[fruits[i]]--;
                    if(m[fruits[i]] == 0)
                        m.erase(fruits[i]);
                    i++;
                }
            }
            k=max(k,j-i+1);
            j++;
        }
        return k;
    }
};