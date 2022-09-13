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
        
        vector<TreeNode*> arrP , arrQ ;
        
        preorder( root , arrP , p);
        preorder( root , arrQ , q);
        
        int n = min( arrP.size() , arrQ.size());
        
        TreeNode* ans = NULL;
        for( int i = 0 ; i < n ;i++){
            if( arrP[i] == arrQ[i] ){
                ans = arrP[i];
            }else{
                break;
            }
        }
        
        return ans;
        
    }
    
    bool preorder( TreeNode* root , vector<TreeNode*> &arr , TreeNode* target ){
        
        if( !root){
            return false;
        }
        
        arr.push_back(root);
        
        if( root == target){
            return true;
        }
        
        if( preorder(root->left , arr , target) || preorder(root->right , arr , target)){
            return true;
        }
        
        arr.pop_back();
        
        return false;     
        
        
    }
    
};