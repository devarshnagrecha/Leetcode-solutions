//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) 
	{
	    int ans = INT_MAX, low = 0, high = n-1, mid, ind;

        while(low<=high)
        {
            mid = (low+high)/2;

            if (nums[low]<=nums[high])
            {
                if (nums[low]<ans)
                {
                    ans = nums[low];
                    ind = low;
                }
                break;
            }
            
            if (nums[low]<=nums[mid])
            {
                if (nums[low]<ans)
                {
                    ans = nums[low];
                    ind = low;
                }
                low = mid+1;
            }

            else if (nums[mid]<=nums[high])
            {
                if (nums[mid]<ans)
                {
                    ans = nums[mid];
                    ind = mid;
                }
                high = mid-1;
            }
        }
        return ind;
	    // code here
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends