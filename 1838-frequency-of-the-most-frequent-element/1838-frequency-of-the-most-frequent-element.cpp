class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) 
    {
        sort (arr.begin(), arr.end());
        
        long long int i = 0;
        long long int n = arr.size();
        long long int j = 0;
        long long int currSum = 0;
        long long int ans = 0;
        
        while (j<n)
        {
            currSum += arr[j];
            long long int reqSum = arr[j]*(j-i+1);
            
            while (arr[j]*(j-i+1)-currSum>k)
            {
                currSum-=arr[i++];
            }
            
            ans = max (ans, j-i+1);
            j++;

        }
        
        return ans;
        
    }
};