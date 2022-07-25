class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        /*
        Iterator lower_bound (Iterator first, Iterator last, const val) 
Iterator upper_bound (Iterator first, Iterator last, const val) 
lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 

and if the value is not present in the vector then it returns the end iterator.
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 
        */
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lo == nums.size() || nums[lo] != target)
            return {-1, -1};
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {lo, hi};
        /*auto bounds = equal_range(nums.begin(), nums.end(), target);
        if (bounds.first == bounds.second)
            return {-1, -1};
        return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};*/
    }
};