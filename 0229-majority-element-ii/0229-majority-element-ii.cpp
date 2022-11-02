class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int count1 = 0, count2 = 0, candidate1 = -1, candidate2 = -1;

        for (int num : nums)
        {
            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;

            else if (count1 == 0)
            {
                count1++;
                candidate1 = num;
            }

            else if (count2 == 0)
            {
                count2++;
                candidate2 = num;
            }

            else
            {
                count1--;
                count2--;
            }
        }

        int temp1 = 0, temp2 = 0;

        // verify if candidate is majority
        for (int num : nums)
        {
            if (num == candidate1)
                temp1++;
            if (num == candidate2)
                temp2++;
        }

        vector<int> ans;

        if (temp1 > nums.size() / 3)
            ans.push_back(candidate1);

        if (temp2 > nums.size() / 3 && candidate1 != candidate2)
            ans.push_back(candidate2);

        return ans;
    }
};