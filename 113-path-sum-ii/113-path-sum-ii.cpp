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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector< vector<int>> result;
        vector< int > path;
        
        dfs( root , targetSum , path , result );
        
        return result;
        
    }
    
    void dfs( TreeNode* root , int targetSum , vector<int> &path , vector< vector<int>> &result){
        
        if( !root){
            return;
        }
        
        path.push_back(root->val);
        
        if( !root->right && !root->left && targetSum - root->val == 0){
            result.push_back(path);
        }
        
        dfs(root->left , targetSum - root->val , path , result);
        dfs(root->right , targetSum - root->val , path , result);
            
        path.pop_back();
        
    }
    
};