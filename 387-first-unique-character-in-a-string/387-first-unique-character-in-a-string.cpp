class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector <int> arr(128,0);
        int ans;
        
        for (int i=0; i<s.size(); i++)
        {
            arr[s[i]]++;
        }
        
        for (int i=0; i<s.size(); i++)
        {
            if (arr[s[i]]==1)
            {
                ans = i;
                break;
            }
        }
        if (ans==s.size())
            return -1;
        else 
            return ans;
    }
};