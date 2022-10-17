class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        map <int,int> mp;
        
        for (auto it:sentence)
        {
            mp[it]++;
        }
        
        if (mp.size()==26)
            return true;
        return false;
        
    }
};