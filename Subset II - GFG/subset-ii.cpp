//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  
    vector<vector<int> > printUniqueSubsets(vector<int> &nums) 
   {
		sort(nums.begin(), nums.end());
        vector<vector<int> > res;
		vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	void subsetsWithDup(vector<vector<int> > &res, vector<int> &nums, vector<int> &vec, int begin) 
    {
		res.push_back(vec);
        
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) 
            { 
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends