// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<int> curr(y+1), prev(y+1,0);
        
        for (int i=1; i<=x; i++)
        {
            curr[0]=0;
            
            for (int j=1; j<=y; j++)
            {
                if (s1[i-1]==s2[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                
                else
                {
                    curr[j]=max(prev[j], curr[j-1]);
                }
            }
            
            prev = curr;
        }
        
        return curr[y];
        
        // your code here
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends