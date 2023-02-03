//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c)
    {
        int i=0,j=0;
        string dir = "r";
        while(1)
        {
            //cout << i << " " << j << " " << dir << endl;
            if (matrix[i][j]==0)
            {
                if (dir=="r")
                    j++;
                if (dir=="l")
                    j--;
                if (dir=="u")
                    i--;
                if (dir=="d")
                    i++;
            }
            
            else
            {
                matrix[i][j]=0;
                if (dir=="u")
                {
                    dir="r";
                    j++;
                }
                else if (dir=="r")
                {
                    dir="d";
                    i++;
                }
                else if (dir=="d")
                {
                    dir="l";
                    j--;
                }
                else if (dir=="l")
                {
                    dir="u";
                    i--;
                }
                
            }
            //cout << i << " " << j << " " << dir << endl;
            if (i<0 || j<0 || i>=r || j>=c)
                break;
        }
        
        if (dir=="u")
            i++;
        if (dir=="d")
            i--;
        if (dir=="l")
            j++;
        if (dir=="r")
            j--;
        
        return {i,j};
        //code here
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends