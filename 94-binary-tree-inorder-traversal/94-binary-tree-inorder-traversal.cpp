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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> arr;
        
        traverse(root , arr);
        
        return arr;
        
    }
    
    void traverse(TreeNode* root, vector<int> &arr){
        
        if( !root){
            return;
        }
        
        traverse(root->left , arr);
        arr.push_back(root->val);
        traverse(root->right , arr);
        
    }
};