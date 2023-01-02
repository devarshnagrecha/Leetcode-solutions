class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool up = false, up2 = false;
        
        if (word.size()<2)
            return true;
        
        if (word[0]>='A' && word[0]<='Z')
        {
            up = true;
        }
        
        if (word[1]>='A' && word[1]<='Z')
        {
            up2 = true;
        }
        
        if (!up && up2)
            return false;
        
        for (int i=2; i<word.size(); i++)
        {
            if (word[i]>='A' && word[i]<='Z' && (up==false || up2==false))
                return false;
            if (word[i]>='a' && word[i]<='z' && up2==true )
                return false;
        }
        
        return true;
        
    }
};