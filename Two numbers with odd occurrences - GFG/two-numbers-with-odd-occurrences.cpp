//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        long long int AxorB = 0;
        for (int i=0; i<n; i++)
        {
            AxorB ^= arr[i];
        }
        
        int bit;
        for (int i=0; i<31; i++)
        {
            if ((AxorB & (1<<i)))
            {
                bit = i;
                break;
            }
        }
        
        long long int a = 0;
        for (int i=0; i<n; i++)
        {
            if ((arr[i] & (1<<bit)))
                a^=arr[i];
        }
        
        long long int b = AxorB^a;
        if (a>b)
            return {a,b};
        return {b,a};
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends