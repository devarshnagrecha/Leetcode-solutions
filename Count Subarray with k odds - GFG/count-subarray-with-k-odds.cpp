//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return atMostKOdd(nums, k) - atMostKOdd(nums, k-1);
    }
    
    int atMostKOdd (vector<int>& nums, int k)
    {
        int n = nums.size(), l = 0, r = 0, ans = 0;

        while(r<n)
        {
            if (nums[r]%2)
                k--;
            while(k<0)
            {
                if(nums[l]%2)
                    k++;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
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
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends