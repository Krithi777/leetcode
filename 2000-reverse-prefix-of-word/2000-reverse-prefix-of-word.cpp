class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>s;
        int i;
        for(i=0;i<word.size();i++)
        {
            s.push(word[i]);
            if(word[i]==ch)
                break;
        }
        if(i==word.size())
          return word;
        i=0;
        while(!s.empty())
        {
            word[i]=s.top();
            s.pop();
            i++;
        }
        return word;
    }
};