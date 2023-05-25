//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) 
    {
        int ans = 0, l = 0, r = 0;

        while(l<n && r<n)
        {
            if (nums[r]==1)
            {
                ans = max(ans,r-l+1);
                r++;
            }

            else
            {
                if (k)
                {
                    ans = max(ans,r-l+1);
                    r++;
                    k--;
                }

                else
                {
                    while(k==0)
                    {
                        if (nums[l]==0)
                            k++;
                        l++;
                    }
                }
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends