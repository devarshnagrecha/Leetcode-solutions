//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(vector<int>&ans, vector<int>arr, int ind, int sum)
    {
        ans.push_back(sum);
        for (int i=ind; i<arr.size(); i++)
        {
            sum+=arr[i];
            solve(ans,arr,i+1,sum);
            sum-=arr[i];
        }
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int>ans;
        solve(ans,arr,0,0);
        sort(ans.begin(), ans.end());
        return ans;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends