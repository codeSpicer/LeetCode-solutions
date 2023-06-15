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
    int maxLevelSum(TreeNode* root) {
        
        int ans = 0;
        int maxSum = INT_MIN;
        int level = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while( !q.empty() ){
            
            int level_sum = 0;
            level += 1;
            int level_size = q.size();
            
            for( int i = 0 ; i < level_size ; i++){
                
                TreeNode* temp = q.front();
                q.pop();
                
                level_sum += temp->val;
                
                if( temp->left){
                    q.push( temp->left);
                }
                if( temp->right){
                    q.push(temp->right);
                }
                
            }
            
            if( level_sum > maxSum){
                ans = level;
                maxSum = level_sum;
            }
            
        }
        cout<<maxSum<<endl;
        return ans;
        
    }
};