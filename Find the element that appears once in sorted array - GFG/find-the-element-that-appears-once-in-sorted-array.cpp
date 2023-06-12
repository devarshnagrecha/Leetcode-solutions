//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int low = 2, high = n-3, mid;
        if(n==1)
            return arr[0];
            
        if (arr[0]!=arr[1])
            return arr[0];
        if (arr[n-1]!=arr[n-2])
            return arr[n-1];
        while(low<=high)
        {
            mid = (low+high)/2;
            //cout << mid << " MID " << arr[mid-1] << " " << arr[mid] << " " << arr[mid+1] << endl;
            if (arr[mid]==arr[mid-1])
            {
                if(mid%2==1)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            
            else if (arr[mid]==arr[mid+1])
            {
                if(mid%2==0)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                //cout << "fdbsf";
                return arr[mid];
            }
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends