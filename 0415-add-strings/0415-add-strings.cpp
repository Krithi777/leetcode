class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        string s="";
        int c=0;
        while(i>=0 && j>=0)
        {
            int k=num1[i]-'0'+num2[j]-'0'+c;
            c=k/10;
            s+=to_string(k%10);
            i--;
            j--;
        }
        while(i>=0)
        {
            int k=num1[i]-'0'+c;
            c=k/10;
            s+=to_string(k%10);
            i--;
        }
        while(j>=0)
        {
            int k=num2[j]-'0'+c;
            c=k/10;
            s+=to_string(k%10);
            j--;
        }
        if(c)
          s+=to_string(c);
        reverse(s.begin(),s.end());
        return s;
    }
};