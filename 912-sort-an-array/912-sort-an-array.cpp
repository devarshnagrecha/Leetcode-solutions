class Solution {
public:
    
    void merge (vector <int> &l, vector <int> &r, vector<int> &ans)
    {
        int i=0, j=0, k=0;
        
        while (i<l.size() && j<r.size())
        {
            if (l[i]<r[j])
            {
                ans[k]=l[i];
                k++;
                i++;
            }
            
            else
            {
                ans[k]=r[j];
                k++;
                j++;
            }
        }
        
        while (i!=l.size())
        {
            ans[k]=l[i];
            k++;
            i++;
        }
        
        while (j!=r.size())
        {
            ans[k]=r[j];
            k++;
            j++;
        }
    }
    
    void mergeSort (vector<int> &nums)
    {
        if (nums.size()<2)
            return;
        
        int mid = nums.size()/2, i, n=nums.size();
        //cout << mid << " ";
        vector<int> l (mid);
        vector<int> r (n-mid);
        
        for(i = 0;i<mid;i++) l[i] = nums[i]; // creating left subarray
	    for(i = mid;i<n;i++) r[i-mid] = nums[i];
        
        mergeSort (l);
        mergeSort (r);
        merge (l,r,nums);
    }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        mergeSort (nums);
        return nums;
    }
};