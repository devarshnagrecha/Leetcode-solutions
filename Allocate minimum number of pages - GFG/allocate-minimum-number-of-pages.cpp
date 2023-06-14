//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool solve (int mid, int arr[], int m, int n)
    {
        
        for (int i=0; i<n; i++)
        {
            if (arr[i]>mid)
                return false;
        }
        int curr = 0, i=0, count=0;
        while (i<n)
        {
            while (i<n && (arr[i]+curr)<=mid)
            {
                curr+=arr[i];
                i++;
            }
            count++;
            curr=0;
        }
        //cout << mid << " M " << count << endl;
        if (count>m)
            return false;
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
        int low = INT_MAX, high = 0, ans=-1, mid;
        if (m>n)
            return -1;
        for (int i=0; i<n; i++)
        {
            low = min(low,arr[i]);
            high += arr[i];
        }
        
        while(low<=high)
        {
            mid = (low+high)/2;
            //cout << mid << " " << solve(mid,arr,m,n) << endl;
            if (solve(mid,arr,m,n))
            {
                ans = mid;
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
        }
        return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends