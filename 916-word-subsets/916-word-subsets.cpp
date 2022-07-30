class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        int n = words1.size(), m = words2.size();
        
        //vector <vector<int> > data(n, vector<int>(26,0));
        
        vector <int> maxFreq (26,0);
        
        for (int i=0; i<m; i++)
        {
            vector <int> temp(26,0) ;
            
            for (int j=0; j<words2[i].size(); j++)
            {
                temp[words2[i][j] - 'a']++;
                maxFreq[words2[i][j] - 'a'] = max(maxFreq[words2[i][j] - 'a'], temp[words2[i][j] - 'a']);
            }
        }
        
        vector <string> ans;

        for (int i=0; i<n; i++)
        {
            vector <int> temp = maxFreq;
            
            for (int j=0; j<words1[i].size(); j++)
            {
                temp[words1[i][j]-'a']--;
            }
            
            int j;
            for (j=0; j<26; j++)
            {
                if (temp[j]>0)
                    break;
            }
            
            if (j==26)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};