class Solution {
public:
    int dp[1000][1000];
    int solve(vector<int>&nums, vector<int>&scores, int i, int j, int k)
    {
        if(k == scores.size()) return 0;
        if(dp[i][k] != 1e9) return dp[i][k];
        int s1 = (scores[k]*nums[i])+solve(nums, scores, i+1, j, k+1);
        int s2 = (scores[k]*nums[j])+solve(nums, scores, i, j-1, k+1);
        return dp[i][k] = max(s1, s2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
         int n = nums.size();
         for(int i=0; i<1000; i++){
             for(int j=0; j<1000; j++){
                 dp[i][j] = 1e9;
             }
         }
        return solve(nums, multipliers, 0, n-1, 0);
    }
};