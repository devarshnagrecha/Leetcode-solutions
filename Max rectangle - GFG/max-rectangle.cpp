//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int>prev_smaller(n),next_smaller(n);
        stack <int> s1,s2;

        for (int i=n-1; i>=0; i--)
        {
            while(!s1.empty() && heights[s1.top()]>=heights[i])
                s1.pop();
            if (s1.empty())
                next_smaller[i] = (n-i-1);
            else
                next_smaller[i] = (s1.top()-i-1);
            s1.push(i);
        }

        for (int i=0; i<n; i++)
        {
            while(!s2.empty() && heights[s2.top()]>=heights[i])
                s2.pop();
            if (s2.empty())
                prev_smaller[i] = (i);
            else
                prev_smaller[i] = (i-s2.top()-1);
            s2.push(i);
        }

        int ans = 0;
        for (int i=0; i<n; i++)
        {
            ans = max (ans,(next_smaller[i]+prev_smaller[i]+1)*heights[i]);
        }
        return ans;
    }

    int maxArea(int matrix[MAX][MAX], int n, int m) 
    {
        vector<int>prev(m);
        for (int i=0; i<m; i++)
        {
            if (matrix[0][i]==1)
                prev[i]=1;
            else
                prev[i]=0;
        }
        int ans = largestRectangleArea(prev);
        for (int i=1; i<n; i++)
        {   
            for (int j=0; j<m; j++)
            {
                if (matrix[i][j]==1)
                    prev[j]++;
                else
                    prev[j]=0;
            }
            ans = max(ans, largestRectangleArea(prev));
        }
        return ans;
        // Your code here
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends