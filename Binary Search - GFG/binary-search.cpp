//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int nums[], int n, int target) 
    {
        int l=0, r=n-1;
        
        while(l<=r)
        {
            int mid = l + (r - l) / 2;
            
            if(nums[mid]==target)
                return mid;
            
            else if (nums[mid]>target)
                r=mid-1;
            
            else
                l=mid+1;
        }
        return -1;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends