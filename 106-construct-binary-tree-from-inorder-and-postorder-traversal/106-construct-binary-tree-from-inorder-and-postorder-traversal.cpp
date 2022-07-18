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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size()-1;
        
        // We will get root element from postorder vector
        // current root = postorder[rootIndex]
        // now, by linear search, from left to right index, we will find the root index in indorder vector 
        // Also, current root = inorder[pivot]
        // Now, from pivot +1 index to right index in inorder, will be part of right subtree of root
        // Now, from left index to pivot - 1 index in inorder, will be part of left subtree of root
        
        // we will decrement the rootindex.
        // if it had been preorder
        
        // preorder : starting rootIndex = 0
        // postorder : starting rootIndex = n-1
        // preorder : make the left subtree first
        // postorder : make the right subtree first
        // preorder : rootIndex value will increment
        // postorder : rootIndex value will decrement
        
        return postorderInorderToTree (inorder,postorder,n, 0, n);
    }
    
    TreeNode * postorderInorderToTree (vector<int>& inorder, vector<int>& postorder, int &rootIndex, int left, int right)
    {
        if (left>right)
            return NULL;
        
        int pivot = left;
        
        while(inorder[pivot]!=postorder[rootIndex])
            pivot++;
        
        rootIndex--;
        
        TreeNode* root = new TreeNode (inorder[pivot]);
        
        root->right = postorderInorderToTree (inorder, postorder, rootIndex, pivot+1,right);
        root->left = postorderInorderToTree (inorder, postorder, rootIndex, left, pivot-1);
        
        return root;
    }
};