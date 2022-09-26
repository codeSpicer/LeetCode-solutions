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
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* ans = new TreeNode();
        TreeNode* holder = ans;
        
        util( root , ans);
        
        return holder->right;
        
    }
    
    void util(TreeNode* root , TreeNode* &ans){
        if( !root) return;
        
        util( root->left , ans);
        
        root->left = NULL;
        
        ans->right = root;
        ans = root;
        
        util(root->right , ans);
        
    }
    
};