//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& nums, int n, int goal)
    {
        return atMostSumK(nums, goal) - atMostSumK(nums, goal-1); 
        // code here
    }
    
    int atMostSumK (vector<int>& nums, int goal)
    {
        if (goal<0)
            return 0;

        int l=0, sum = 0, ans = 0, r=0, n=nums.size();

        while(l<n && r<n)
        {
            sum += nums[r];
            while(sum>goal)
            {
                sum -= nums[l];
                l++;
            }
            ans += r-l+1;
            r++;   
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends