// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, int wt[], int val[], int i, vector<vector<int>> &dp)
    {
        if (i==0)
        {
            if (wt[i]<=w)
                return val[i];
            return 0;
        }
        
        if (dp[i][w]!=-1)
            return dp[i][w];
            
        int take = INT_MIN;
        if (wt[i]<=w)
            take = val[i] + solve(w-wt[i],wt,val,i-1,dp);
        
        int notTake = solve(w,wt,val,i-1,dp);
        
        return dp[i][w] = max(take,notTake);
    }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int>(w+1,-1));
        return solve(w,wt,val,n-1,dp);
       // Your code here
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends