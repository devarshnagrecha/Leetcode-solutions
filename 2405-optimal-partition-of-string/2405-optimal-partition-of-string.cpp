class Solution {
public:
    int partitionString(string s) 
    {
        vector<int>v(26,0),m(26,0);
        
        int ans = 1;
        
        for (int i=0; i<s.size(); i++)
        {
            if (v[s[i]-'a']!=0)
            {
                v = m;
                ans++;
            }    
            v[s[i]-'a']++;
            
        }
        
        return ans;
        
    }
};