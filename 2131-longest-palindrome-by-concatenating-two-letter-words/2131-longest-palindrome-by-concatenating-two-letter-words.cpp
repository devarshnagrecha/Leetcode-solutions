class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int ans = 0;
        bool flag=0;
        
        map <pair<char,char>, int> data;
        
        for (int i=0; i<words.size(); i++)
        {
            data[{ words[i][0], words[i][1] }]++;
        }
        
        for (int i=0; i<words.size(); i++)
        {
            if (data[{ words[i][0], words[i][1] }] > 0)
            {
                if (data[{ words[i][1], words[i][0] }] > 0 && words[i][0]!=words[i][1])
                {
                    ans+=4;
                    data[{ words[i][0], words[i][1] }]--;
                    data[{ words[i][1], words[i][0] }]--;
                }
                
                else if (words[i][0] == words[i][1] && data[{ words[i][0], words[i][1] }] > 1)
                {
                    ans+=4;
                    data[{ words[i][0], words[i][1] }]--;
                    data[{ words[i][1], words[i][0] }]--;
                }
            }
        }
        
        for (int i=0; i<words.size(); i++)
        {
            if (data[{ words[i][0], words[i][1] }] > 0 && flag==0)
            {
                if (words[i][0]==words[i][1])
                {
                    flag = 1;
                    ans+=2;
                    data[{ words[i][0], words[i][1] }]--;
                }
            }
        }
        
        return ans;
        
        
    }
};