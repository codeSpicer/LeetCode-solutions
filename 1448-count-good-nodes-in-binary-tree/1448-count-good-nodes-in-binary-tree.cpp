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
    int counter = 0;
    
    int goodNodes(TreeNode* root) {
        
        // we use recursion to do dfs while passing the greatest node val in the path as parameter
        // if a greater value is found then counter is increased and max_path_val is updated
        // then we call it for children nodes
        
        util( root , root->val);
        
        return counter;
        
    }
    
    void util( TreeNode* root , int val){
        
        if( !root){
            return ;
        }
        
        if( root->val >= val){
            counter++;
            val = root->val;
        }
        
        
        
        util( root->left , val);
        util( root->right , val);
        
    }
    
};