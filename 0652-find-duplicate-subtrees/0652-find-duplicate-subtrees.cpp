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
    
    string solve(vector<TreeNode*>&ans, map<string,int>&mp, TreeNode* root)
    {
        if (!root)
            return "";
        
        string s = to_string(root->val)+","+solve(ans,mp,root->right)+","+solve(ans,mp,root->left);
        if (++mp[s]==2)
            ans.push_back(root);
        return s;
        
    }
              
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*>ans;
        map <string,int> mp;
        solve (ans,mp,root);
        return ans;
    }
};
    
    
              
