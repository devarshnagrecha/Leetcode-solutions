class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int start=0,end=1e9;
        
        while(start<end)
        {
            int mid = (start+end)/2;
            
            long double count = 0;
            
            for (int i=0; i<nums.size(); i++)
            {
                count += ceil(1.0*nums[i]/mid);
            }
            
            if (count>threshold)
                start=mid+1;
            else
                end=mid;
        }
        
        return start;
        
    }
};