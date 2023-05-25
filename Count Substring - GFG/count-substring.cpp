//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) 
    {
        int n = s.size(), r= 0, l=0, ans = 0;
        unordered_map<char,int>mp;
        while(r<n)
        {
            mp[s[r]]++;
            
            while(mp.size()==3)
            {
                ans += (n-r);
                mp[s[l]]--;
                if (mp[s[l]]==0)
                    mp.erase(s[l]);
                
                l++;
            }
            r++;
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends