//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        int row = m, col = n-1;
        int i=0,j=-1;
        
        while(1)
        {
            int temp1 = row, temp2 = col;
            while(row && k)
            {
                row--;
                j++;
                k--;
            }
            
            // cout << " A " << i << " " << j << endl;
            while(col && k)
            {
                col--;
                i++;
                k--;
            }
                // cout <<  " B " << i << " " << j << endl;
            
            row = temp1-1, col = temp2-1;
            while(row && k)
            {
                row--;
                j--;
                k--;
            }
            
                // cout <<  " C " << i << " " << j << endl;
            while(col && k)
            {
                col--;
                i--;
                k--;
            }
            
                // cout <<  " D " << i << " " << j << endl;
            row = temp1-2, col  = temp2-2;
            
            if (!k)
            {
                // cout << i << " " << j << endl;
                return a[i][j];
            }
        }
        
        return -1;
 		// Your code goes here.
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends