//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool solve(vector<int>&arr, int i, int sum, vector<vector<int>> &dp)
    {
        if (sum==0)
            return true;
        if (i==0)
            return arr[0]==sum;
        
        if (dp[i][sum]!=-1)
            return dp[i][sum];
            
        bool notTake = solve(arr,i-1,sum,dp);
        bool take = false;
        
        if (arr[i]<=sum)
            take = solve(arr,i-1,sum-arr[i],dp);
        
        return dp[i][sum] = take || notTake;
    }
    
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        dp[0][arr[0]]=true;
        
        for (int i=0; i<n; i++)
        {
            dp[i][0]=true;
        }
        
        for (int i=1; i<n; i++)
        {
            for (int j=1; j<=sum; j++)
            {
                bool take = false;
                if (arr[i]<=j)
                {
                    take = dp[i-1][j-arr[i]];
                }
                bool notTake = dp[i-1][j];
                dp[i][j]=take | notTake;
            }
        }
        return dp[n-1][sum];
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
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends