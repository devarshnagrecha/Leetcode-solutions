/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        solve (root, sum, 0);
        return sum;
    }
    
    void solve (TreeNode* root, int &sum, int prev)
    {
        if (!root)
            return;
        
        root->val += prev*10;
        
        if (!root->left && !root->right)
            sum += root->val;
        
        solve(root->left, sum, root->val);
        solve(root->right, sum, root->val);
        
    }
};