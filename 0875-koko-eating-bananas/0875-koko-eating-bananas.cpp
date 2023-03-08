class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int end = *max_element(piles.begin(),piles.end());
        int start = 0;
        int mid;
        
        
        while (start<=end)
        {
            mid = (start+end)/2;
            
            long double count = 0;
            
            for (int i=0; i<piles.size(); i++)
            {
                count += ceil(1.0*piles[i]/mid);
            }
            
            if (count>h)
            {
                start = mid+1;
            }
            
            else
            {
                end = mid-1;
            }
        }
        
        return start;
    }
};