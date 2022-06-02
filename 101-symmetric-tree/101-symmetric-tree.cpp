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
    bool isSymmetric(TreeNode* root) {
        
        if( root==NULL){
            return true;
        }
        
        return symmetricTest(root->left , root->right);
        
    }
    
    bool symmetricTest( TreeNode* r1 , TreeNode* r2){
        
        if( !r1 && !r2){        // if both child are NULL then the node is symmetric
            return true;
        }
        
        if( !r1 || !r2){        // if one child is NULL it is not symmetric
            return false;
        }
        
        if( r1->val != r2->val){
            return false;
        }
        
        // calling for opposite nodes to check if the tree is symmetrical
        return symmetricTest( r1->left , r2->right) && symmetricTest( r2->left , r1->right);
    }
    
};


        // honoralble mention to ->
        //do a inorder traversal and add all node vals to and array and check of pallindrome then
        // 195/198 testcases idk how this didnt work