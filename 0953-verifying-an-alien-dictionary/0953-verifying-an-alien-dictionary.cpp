class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char,int>mp;
        for (int i=0; i<order.size(); i++){
            mp[order[i]]=i;
        }
        
        for (int i=0; i<words.size()-1; i++)
        {
            auto s1 = words[i];
            auto s2 = words[i+1];
            
            int j=0,n= min(s1.size(),s2.size());
            
            while(j<n && s1[j]==s2[j])
            {
                j++;
            }
            
            if (j==n)
            {
                if (s2.size()==n && s1!=s2)
                    return false;
                continue;
            }
            
            if (mp[s1[j]] > mp[s2[j]])
                return false;
        }
        return true;
        
    }
};