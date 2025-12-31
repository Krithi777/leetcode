class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int c = 0;
        string s = "";
        while (i >= 0 || j >= 0 || c) {
            int si = c;
            if (i >= 0) si += a[i--] - '0';
            if (j >= 0) si += b[j--] - '0';
            s = char(si % 2 + '0') + s;  
            c = si / 2;                   
        }
        return s;
    }
};
