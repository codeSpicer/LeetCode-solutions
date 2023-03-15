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
    bool isCompleteTree(TreeNode* root) {
        
        if(!root){
            return true;
        }
        
        queue<TreeNode*> st;
        
        st.push( root);
        
        while( !st.empty() ){
            
            TreeNode* temp = st.front();
            st.pop();
            
            if( temp ){
                st.push( temp->left);
                st.push( temp->right);
            }else{
                while( !st.empty()){
                    if( st.front() == NULL){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
            
        }
        
        return true;
        
    }
};