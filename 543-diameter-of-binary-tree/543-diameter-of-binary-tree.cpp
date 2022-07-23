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
    
    int solve (TreeNode *root, int &ans)
    {
        if (root==NULL)
            return 0;
        
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        
        ans = max (ans, r+l);
        return max(r,l)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int d=0;
        solve(root, d);
        return d;   
    }
};