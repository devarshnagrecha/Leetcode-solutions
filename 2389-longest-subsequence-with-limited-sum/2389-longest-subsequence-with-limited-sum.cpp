class Solution {
public:
    vector<int> answerQueries(vector<int> A, vector<int>& queries) 
    {
        sort(A.begin(), A.end());
        vector<int> res;
        for (int i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        for (int& q: queries)
        {
            /*if (upper_bound(A.begin(), A.end(), q)!=A.end())
            cout << *upper_bound(A.begin(), A.end(), q) << " ";*/
            res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin());
        }
            
        return res;
    }
};