class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        for (int left = 0, right = nums.size() - 1; left <= right;)
        {
            const int middle = (left + right) / 2;

            if (nums[middle] < target)
            {

                if (nums[left] > nums[middle] && target > nums[right])
                    right = middle - 1;

                else 
                    left = middle + 1;

            }

            else if (nums[middle] > target)
            {
                if (nums[middle] > nums[right] && target < nums[left])
                    left = middle + 1;

                else 
                    right = middle - 1;

            }

            else 
                return middle;

        }

        return -1;
    }
};