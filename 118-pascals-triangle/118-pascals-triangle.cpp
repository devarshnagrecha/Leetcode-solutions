class Solution {
public:
   vector<vector<int>> generate(int numRows) 
   {
       // answer 2d vector
	    vector<vector<int>> ret;
       
	    for (int i = 0; i < numRows; i++) 
        {
            // next row will have size, one more than previous row
		    vector<int> row(i + 1, 1);
		    for (int j = 1; j < i; j++) 
            {
                // current colomn in current row will be sum of current column in previous
                // row and previous column in previous row
			    row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
		    }
		    ret.push_back(row);
	    }
	    return ret;
    }
};