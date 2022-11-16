/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        long long int low = 0, high = n, mid;
        
        while (low<=high)
        {
            mid = (low+high)/2;
            long long int x = guess(mid);
            
            if (x==0)
            {
                return mid;
            }
            
            else if (x==1)
            {
                low = mid+1;
            }
            
            else
            {
                high = mid-1;
            }
        }
        
        return low;
        
    }
};