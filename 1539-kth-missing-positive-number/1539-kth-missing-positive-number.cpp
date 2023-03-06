class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int count = arr[0]-1, i=1, n=arr.size();
        
        while(i<n && count<k)
        {
            count += (arr[i]-arr[i-1]-1);
            i++;
        }
        
        if (count<k)
            return arr[n-1] + (k-count);
        return arr[i-1] + (k-count)-1;
        
    }
};