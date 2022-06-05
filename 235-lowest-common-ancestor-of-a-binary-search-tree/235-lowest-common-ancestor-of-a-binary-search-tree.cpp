/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
         // using the property of binary search trees we can know when we have arrived at the LCA
        // when the 2 decendant nodes are at different sub trees of a node then the current node is LCA 
        
        if( p->val < root->val && q->val < root->val ){
            return lowestCommonAncestor( root->left , p , q );     
            // if both nodes are smaller than root node we call function for left child
        }
        if( p-> val > root->val && q->val >root->val){
            return lowestCommonAncestor(root->right , p , q);
            // if both nodes are larger then root node we call func for right child
        }
        
        return root;    // returns lca
        
    }
};