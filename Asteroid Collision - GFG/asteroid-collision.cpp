//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &arr) 
    {
        stack <int> st;

        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i]>0)
                st.push(arr[i]);
            
            else
            {
                while(!st.empty() && st.top()>0 && st.top()<abs(arr[i]))
                {
                    st.pop();
                }

                if (st.empty() || st.top()<0)
                    st.push(arr[i]);

                else if (st.top()==abs(arr[i]))
                    st.pop();
            }
        }
        vector<int> ans(st.size());
        for(int i=ans.size()-1; i>=0; i--)
        {
            ans[i]=st.top();
            st.pop();
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
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends