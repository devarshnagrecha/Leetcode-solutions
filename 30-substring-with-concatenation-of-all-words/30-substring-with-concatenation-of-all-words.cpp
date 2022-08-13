class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int totWords = words.size();
        int lenWords = words[0].size();
        int tot = totWords*lenWords;
        
        unordered_map <string,int> comp;
        
        if (s.size()<tot)
            return {};
        
        vector <int> ans;
        
        for (auto it:words)
        {
            comp[it]++;
        }
        
        for (int i=0; i<=s.size()-tot; i++)
        {
            unordered_map <string,int> temp = comp;
            int j;
            
            for (j=0; j<totWords; j++)
            {
                string str = s.substr(i+j*lenWords, lenWords);
                if (temp.count(str)==0)
                    break;
                
                else if (temp[str]!=0)
                    temp[str]--;
                
                else
                    break;
            }
            
            if (j==totWords)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};