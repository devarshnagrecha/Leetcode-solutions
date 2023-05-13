//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int n, vector<int> &a) 
    {
        if (n==1)
            return a[0];
            
        vector<long long int>dp(n,0);
        
        dp[0]=a[0];
        dp[1]=max(a[1], a[1]+a[0]);
        
        for (int i=2; i<n; i++)
        {
            dp[i]=max(dp[i-1],dp[i-2])+a[i];
        }
        return max(dp[n-1],dp[n-2]);
        
        // code here
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends