//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r)
    {
        int mod = 1e9 + 7;
        
        if (n<r)
            return 0;
        if (n==r)
            return 1;
        
        r = r<(n-r)?r:n-r;
        
        vector<int>dp(r+1,0);
        dp[0]=1;
        
        for (int i=1; i<=n; i++)
        {
            for (int j=r; j>=0; j--)
            {
                dp[j] = (dp[j]%mod + dp[j-1])%mod;
            }
        }
        
        return dp[r];
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends