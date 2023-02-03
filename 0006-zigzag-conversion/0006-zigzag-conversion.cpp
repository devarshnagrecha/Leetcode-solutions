class Solution {
public:
    string convert(string s, int n) 
    {
        if (n==1)
            return s;
        vector<char>adj[n];
        adj[0].push_back(s[0]);
        
        int it=1;
        
        while(it<s.size())
        {
            for (int i=1; i<=n-1; i++)
            {
                if(it>=s.size())
                    break;
                adj[i].push_back(s[it]);
                it++;
            }
            for (int i=n-2; i>=0; i--)
            {
                if(it>=s.size())
                    break;
                adj[i].push_back(s[it]);
                it++;
            }
        }
        
        string ans = "";
        for (auto it:adj)
        {
            for (auto ct:it)
            {
                //cout << ct << " ";
                ans+=ct;
            }
            //cout << endl;
        }
        return ans;
        
    }
};