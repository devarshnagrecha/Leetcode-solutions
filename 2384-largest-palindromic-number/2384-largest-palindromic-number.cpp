class Solution {
public:
    string largestPalindromic(string num) 
    {
        map <int,int> mp;
        
        string s = "",t="";
        
        bool flag = false;
        
        for (auto it:num)
        {
            mp[it-'0']++;
        }
        
        int i=9;
        while (i>=0)
        {
            if (mp[i]>1)
            {
                mp[i] -= 2;
                s+=to_string(i);
            }
            
            else
                i--;
        }
        
        for (int i=9; i>=0; i--)
        {
            if (mp[i]==1)
            {
                s+=to_string(i);
                flag = true;
                break;
            }
        }
        
        //cout << s << endl;
        
        if (s[0]=='0')
        {
            if (s[s.size()-1]!='0')
            {
                string str="";
                str += s[s.size()-1];
                return str;
            }
            
            return "0";
        }
        
        t = s;
        
        if (flag)
            t.pop_back();
        
        reverse(t.begin(), t.end());
        
        s += t;
        
        return s;
        
    }
};