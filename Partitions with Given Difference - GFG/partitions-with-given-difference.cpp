//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) 
    {
        int sum = accumulate(arr.begin(),arr.end(),0);
        int x = sum - d, mod = 1e9+7;
        if (x<0 || x%2)
            return 0;
        x/=2;
        vector<vector<int>> dp(n, vector<int>(x+1,0));
        
        if (x>=arr[0])
            dp[0][arr[0]]=1;
            
        if (arr[0]==0)
            dp[0][0]=2;
        else
            dp[0][0]=1;
        
            
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<=x; j++)
            {
                int take = 0;
                if (arr[i]<=j)
                    take = dp[i-1][j-arr[i]];
                int notTake = dp[i-1][j];
                dp[i][j]=(take + notTake)%mod;
            }
        }
        
        return dp[n-1][x]%mod;
        //return perfectSum(arr,n,x);
        // Code here
    }
    
    int perfectSum(vector<int>&arr, int n, int sum)
	{
	    vector<vector<int>> dp(n, vector<int>(sum+1,0));
	    int mod = 1e9+7;
	    if (sum>=arr[0])
	        dp[0][arr[0]] = 1;
	    
	    if (arr[0]==0)
	        dp[0][0] = 2;
	    else   
	        dp[0][0] = 1;
	        
	    for (int i=1; i<n; i++)
	    {
	        for (int curr=0; curr<=sum; curr++)
	        {
	            int notTake = dp[i-1][curr];
	            
	            int take = 0;
	            
	            if (curr>=arr[i])
	                take = dp[i-1][curr-arr[i]];
	                
	            dp[i][curr] = (take + notTake)%mod;
	        }
	    }
	    return dp[n-1][sum]%mod;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends