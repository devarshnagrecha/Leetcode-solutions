//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int n)
    {
        int mod = 1e9+7;
        long int dp[n+1];
        
        dp[0] = 0;
        dp[1] = 0;
        
        if (n>1)
            dp[2] = 3;
            
        if(n>2)
            dp[3] = 6;
            
        for (int i=4; i<=n; i++)
        {
            dp[i] = ((dp[i-1]*2)%mod + (dp[i-2]*3)%mod)%mod;
        }
        return dp[n]%mod;
        // code here 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends