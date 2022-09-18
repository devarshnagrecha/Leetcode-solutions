class Solution {
public:
    int trap(vector<int>& height) 
    {
        int i=0, j=height.size()-1, maxLeft = 0, maxRight = 0;

        if (j<2)
            return 0;
        
        int ans = 0;
        while(i<j)
        {
            if (height[j]>height[i])
            {
                if (height[i]>=maxLeft)
                    maxLeft = height[i];
                else
                    ans += maxLeft-height[i];
                
                i++;
            }
            
            else
            {
                if (height[j]>=maxRight)
                    maxRight = height[j];
                else
                    ans += maxRight-height[j];
                j--;
            }
        }
        return ans;
        
    }
};