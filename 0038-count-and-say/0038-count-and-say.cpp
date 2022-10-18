class Solution {
public:
    
    string solve (string s)
    {
        string ans="";

        int count=1;
        
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]==s[i-1])
            {
                count++;
            }
            
            else
            {
                string temp = to_string(count);
                ans += temp;
                ans.push_back(s[i-1]);
                count=1;
            }
        }
        
        string temp = to_string(count);
        ans += temp;
        ans.push_back(s[s.size()-1]);
        return ans;
    }
    
    
    string countAndSay(int n) 
    {
        vector <string> data;
        
        data.push_back("1");
        data.push_back("11");
        
        for (int i=2; i<n; i++)
        {
            string str = solve(data[i-1]);
            
            data.push_back(str);
        }
        
        return data[n-1];
        
        
    }
};