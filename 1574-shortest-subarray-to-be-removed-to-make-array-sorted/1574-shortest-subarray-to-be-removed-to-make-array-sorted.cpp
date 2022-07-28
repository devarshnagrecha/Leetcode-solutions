class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) 
    {
        int n = A.size(), j;
        
        for (j = n - 1; j > 0; --j)
            if (A[j - 1] > A[j])
                break;
        
        if (j == 0) 
            return 0;
        
        int res = j;
        
        for (int i = 0; i < n; ++i) 
        {
            if (i > 0 && A[i - 1] > A[i]) 
                break;
            
            while (j < n && A[i] > A[j])
                ++j;
            
            res = min(res, j - i - 1);
        }
        
        return res;
    }
};