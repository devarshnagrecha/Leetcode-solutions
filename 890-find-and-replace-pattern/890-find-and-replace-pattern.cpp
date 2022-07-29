class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        
        for (auto it:words)
        {
            map <char, char> mp;
            map <char,bool> visited;
            bool flag=true;
            
            if (it.size()!=pattern.size())
                continue;
            
            for (int i=0; i<it.size(); i++)
            {
                if (!mp[pattern[i]])
                {
                    if (visited[it[i]])
                    {
                        flag = false;
                        break;
                    }
                    
                    else
                    {
                        mp[pattern[i]] = it[i];
                        visited[it[i]]=true;
                    }
                    
                }
                    
                else
                {
                    if (mp[pattern[i]]!=it[i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            
            if (flag)
                ans.push_back(it);
        }
        
        return ans;
    }
    
    
};