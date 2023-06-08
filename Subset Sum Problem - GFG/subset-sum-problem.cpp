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
        //vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        vector<int>prev(sum+1),curr(sum+1);
        prev[0]=true;
        if (arr[0]<=sum)
            prev[arr[0]]=true;
        
        
        for (int i=1; i<n; i++)
        {
            curr[0]=true;
            for (int j=1; j<=sum; j++)
            {
                bool take = false;
                if (arr[i]<=j)
                {
                    take = prev[j-arr[i]];
                }
                bool notTake = prev[j];
                curr[j]= take | notTake;
            }
            prev=curr;
            
        }
        return prev[sum];
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