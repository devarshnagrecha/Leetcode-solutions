//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	vector<int> find(int arr[], int n , int target )
    {
        int lo = lower_bound(arr, arr+n, target) - arr;
            if (lo == n || arr[lo] != target)
                return {-1, -1};
            int hi = upper_bound(arr, arr+n, target) - arr - 1;
            return {lo, hi};
        // code here
    }
	int count(int arr[], int n, int x) {
	    vector<int>ans = find(arr,n,x);
	    if (ans[0]==-1)
	        return 0;
	       return ans[1]-ans[0]+1;
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends