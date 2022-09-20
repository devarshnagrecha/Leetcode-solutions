class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        vector<long long> ans(arr.size(),0);
        
        unordered_map <int,vector<long long int>> adj;
        
        for (int i=0; i<arr.size(); i++)
        {
            adj[arr[i]].push_back(i);
        }
        
        for (auto it:adj)
        {
            int n = it.second.size();
            
            if(n==1)
                continue;
            
            vector <long long int> temp = it.second, pref(n), suff(n);
            
            pref[0] = temp[0];
            for (int i=1; i<n; i++)
            {
                pref[i]=pref[i-1]+temp[i];
            }
            
            suff[n-1] = temp[n-1];
            for (int i=n-2; i>=0; i--)
            {
                suff[i]=suff[i+1]+temp[i];
            }
            
            for (int i=1; i<n-1; i++)
            {
                ans[temp[i]] = temp[i]*i - pref[i-1] + suff[i+1] - temp[i]*(n-i-1);
            }
            
            /*cout << it.first << endl;
            for (auto ct:pref)
                cout << ct << " ";
            cout << endl;
            for (auto ct:suff)
                cout << ct << " ";
            cout << endl;
            for (auto ct:temp)
                cout << ct << " ";
            cout << endl;
            cout << endl;*/
            
            ans[temp[0]] = suff[1] - temp[0]*(n-1);
            ans[temp[n-1]] = temp[n-1]*(n-1) - pref[n-2];
        }
        
        return ans;
    }
};