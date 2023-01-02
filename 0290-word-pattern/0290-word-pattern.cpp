class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map <char,string> mp;
        unordered_map <string,bool> vis;
        int n = s.size(),i=0;
        
        for (auto it:pattern)
        {
            string str = "";
            while(i<n && s[i]!=' ')
            {
                str+=s[i];
                i++;
            }
            i++;
            
            if (mp.find(it)!=mp.end())
            {
                if (mp[it]!=str)
                    return false;
            }
            
            else
            {
                if (vis[str])
                    return false;
                
                mp[it]=str;
                vis[str]=true;
            }
            
            //cout << it << " " << str << endl;
        }
        
        cout << i << endl;
        if (i!=n+1)
            return false;
        return true;
    }
};