//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int XxorY = 0;
        for (auto it:nums)
        {
            XxorY^=it;
        }
        
        int bit = XxorY & -XxorY;
        int x = 0, y = 0;
        for (auto it:nums)
        {
            if (it&bit)
                x^=it;
            else
                y^=it;
        }
        if (x>y)
            swap(x,y);
        return {x,y};
        // Code here.
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends