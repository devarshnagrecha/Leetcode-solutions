//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if (image[sr][sc]==newColor)
            return image;
        solve(sr,sc,newColor,image,image[sr][sc]);
        return image;
        // Code here 
    }
    
    void solve(int sr, int sc, int newColor, vector<vector<int>>& image, int oldColor)
    {
        if (sr<0 || sc<0 || sr>=image.size() || sc>=image[sr].size() || image[sr][sc]!=oldColor)
            return;
        image[sr][sc]=newColor;
        solve(sr+1,sc,newColor,image,oldColor);
        solve(sr-1,sc,newColor,image,oldColor);
        solve(sr,sc+1,newColor,image,oldColor);
        solve(sr,sc-1,newColor,image,oldColor);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends