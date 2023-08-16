//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        long long arr[n+1], mod = 1e9+7;
         arr[0]=1;
         
         for(int k=1;k<=n;k++)
         {
            long long res=0;
            
            for(int i=0;i<k;i++)
            {
                res+=(arr[i]*arr[k-i-1])%mod;
            }
            arr[k]=res%mod;
        }
        return arr[n]%mod;
        //code here
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends