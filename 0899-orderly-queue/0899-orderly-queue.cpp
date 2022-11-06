class Solution {
public:
    string orderlyQueue(string s, int k) 
    {
        if (k>1)
        {
            sort (s.begin(), s.end());
            return s;
        }
        
        string ans = s;
        int n = s.size();
        
        while (n--)
        {
            char c = s[0];
            s = s.substr(1,s.size()-1);
            s += c;
            //cout << s << endl;
            ans = min (ans,s);
        }
        
        return ans;
        
    }
};