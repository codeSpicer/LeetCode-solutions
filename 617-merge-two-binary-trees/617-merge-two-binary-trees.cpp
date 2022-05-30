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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if( root1 == NULL){
            return root2;
        }
        if( root2 == NULL){     // 2 recursion terminating statements
            return root1;
        }
        
        root1->val += root2->val;       // we add the total of both nodes in root1
        
        root1->left = mergeTrees( root1->left , root2->left);  // calling it recursively for both child
        root1->right = mergeTrees( root1->right , root2->right);    //storing it in childs of root1
        
        return root1;
        
    }
};