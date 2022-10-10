class Solution {
public:
    string breakPalindrome(string s) 
    {
        if (s.size()==1)
            return "";
        
        int index = -1;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]!='a')
            {
                index = i;
                break;
            }
        }
        
        if (index==-1)
        {
            s[s.size()-1]='b';
            return s;
        }
        
        if (s.size()%2==1 && index==s.size()/2)
            s[s.size()-1]='b';
        else
            s[index]='a';
        return s;
        
    }
};