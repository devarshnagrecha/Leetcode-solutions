class Solution {
public:
    
    bool isValid (int mid, vector<int>&weights, int days)
    {
        int count = 0, sum = 0;
        for (int i=0; i<weights.size(); i++)
        {
            if (sum + weights[i] <= mid)
            {
                sum+=weights[i];
            }
            
            else
            {
                //cout << sum << " ";
                if (weights[i]>mid)
                    return false;
                sum = weights[i];
                count++;
                // i--;
            }
        }
        
        if (sum)
            count++;
        //cout << count << " " << days << endl;
        if (count<=days)
            return true;
        return false;
    }
    
    
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int s = 0, e = INT_MAX, mid;
        
        while(s<=e)
        {
            mid = (s+e)/2;
            
            if (isValid(mid, weights, days))
            {
                e = mid-1;
            }
            
            else
            {
                s = mid + 1;
            }
        }
        
        
        return s;
        
    }
};