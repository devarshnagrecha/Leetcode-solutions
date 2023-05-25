//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) 
    {
        int start=0,end=0,n=s.size(),countMax=0,ans=0;
        
        vector<int>count(26,0);
        
        for (; end<n; end++)
        {
            count[s[end]-'A']++;
            countMax = max (countMax, count[s[end]-'A']);
            
            if ((end-start+1-countMax) > k)
            {
                ans = max(ans,(end-start));
                count[s[start]-'A']--;
                start++;
            }
        }
        
        return max(ans,end-start);
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends