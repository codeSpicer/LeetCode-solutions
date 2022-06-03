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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // idea we can substract the value of node from the target sum can call for both child nodes
        // like for level 1) sub 5 from target
        //                2) sub 4 and 8 resp from both calls 
        // and if the value when recursion reaches the leaf node is 0 that returns true
        // we can return or value from 2 child nodes so that it gets returned to the top

        if(root == NULL){
            return false;
        }
        
        targetSum -= root->val;
        
        if (targetSum == 0 && root->left ==  NULL && root->right == NULL){
            return true;
        } 
        
        return ( hasPathSum(root->left , targetSum) || hasPathSum(root->right , targetSum ));
        
    }
};