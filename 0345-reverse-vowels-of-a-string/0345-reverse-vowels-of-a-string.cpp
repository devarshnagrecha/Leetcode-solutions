class Solution {
public:
    string reverseVowels(string s) 
    {
        string t="";
        
        for (char it: s)
        {
            if (it=='a' || it=='e' || it=='i' || it=='o' || it=='u' || it=='A' || it=='E' || it=='I' || it=='O' || it=='U')
                t+=it;
        }
        
        reverse(t.begin(), t.end());
        
        int j = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                s[i]=t[j];
                j++;
            }
        }
        
        return s;
    }
};