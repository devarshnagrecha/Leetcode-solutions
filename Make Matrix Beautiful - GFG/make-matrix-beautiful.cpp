//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int maxi1 = 0, ans = 0, maxi2 = 0;
        for (int i=0; i<n; i++)
        {
            int sum = 0;
            for (int j=0; j<n; j++)
            {
                sum += matrix[i][j];
            }
            maxi1 = max(maxi1,sum);
        }
        
        for (int i=0; i<n; i++)
        {
            int sum = 0;
            for (int j=0; j<n; j++)
            {
                sum += matrix[j][i];
            }
            maxi2 = max(maxi2,sum);
        }
        
        if (maxi1>maxi2)
        {
            for (int i=0; i<n; i++)
            {
                int sum = 0;
                for (int j=0; j<n; j++)
                {
                    sum += matrix[i][j];
                }
                ans += maxi1 - sum;
            }
        }
        
        else
        {
            for (int i=0; i<n; i++)
            {
                int sum = 0;
                for (int j=0; j<n; j++)
                {
                    sum += matrix[j][i];
                }
                ans += maxi2 - sum;
            }
            
        }
        
        return ans;
        
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends