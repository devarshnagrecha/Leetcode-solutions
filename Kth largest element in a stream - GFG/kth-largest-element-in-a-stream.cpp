//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) 
    {
        vector<int> ans;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for (int i=0; i<n; i++)
        {
            pq.push(arr[i]);
            
            if (pq.size()>k)
                pq.pop();
            
            if (pq.size()==k)
                ans.push_back(pq.top());
            else
                ans.push_back(-1);
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends