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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if( depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }else{
            dfs(root , val , depth);
        }
        
        return root;
        
    }
    
    void dfs(TreeNode* root, int val, int depth) {
        
        if( !root){
            return ;
        }
        
        if( depth - 1 == 1){
            
                TreeNode* l = new TreeNode( val);
                l->left = root->left;
                root->left = l;
            
                TreeNode* r = new TreeNode( val);
                r->right = root->right;
                root->right = r;
        }
        
        dfs(root->left , val , depth -1);
        dfs(root->right , val , depth -1);

        
    }
    
    
    
};