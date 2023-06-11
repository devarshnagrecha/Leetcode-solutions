//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestChain(int n, vector<string>& words) 
    {
        sort (words.begin(), words.end(), cmp);
        
        int maxi=1;
        vector<int>dp(n,1);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (check(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i]= dp[j]+1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        return maxi;
        // Code here
    }
    
    bool check(string s, string t)
    {
        if (s.size()-1!=t.size())
            return false;
        int i=0, j=0, n=s.size();
        while(i<n)
        {
            if (s[i]==t[j])
            {
                i++;
                j++;
            }

            else
            {
                i++;
            }
        }

        if (i==n && j==n-1)
            return true;
        return false;
    }

    static bool cmp (string a, string b)
    {
        return a.size()<b.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends