class Solution {
public:
    string frequencySort(string s) 
    {
        map <char,int> mp;
        
        for (auto it:s)
            mp[it]++;
        
        vector <string> data(s.size()+1, "");
        
        for (auto it:mp)
        {
            string s(it.second, it.first);
            data[it.second]+=s;
        }
        
        string ans;
        for (int i=data.size()-1; i>=0; i--)
        {
            if (data[i]!="")
                ans += data[i];
        }
        
        return ans;
        
        
    }
};