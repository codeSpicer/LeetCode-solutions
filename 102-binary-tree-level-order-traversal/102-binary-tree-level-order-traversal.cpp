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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> arr;        // the return arr
        if( !root ){
            return arr;
        }
        queue<TreeNode*> q;             // queue for doing BFS
        q.push(root);
        q.push(NULL);                   // NULL to mark end of one level
        vector<int> row;                // row to be pushbacked into arr because c++ sucks a bit
        
        while( !q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if( temp == NULL){
                arr.push_back(row);     // if we get null form queue that means the level ended
                                        //and we push the row in 2d arr
                row.resize(0);      // resize row for next level
                if( !q.empty()){
                    q.push(NULL);   // if q not empty we push a null which marks the level end  
                                    //after the current levels child nodes pushed in the queue
                }
            }else{
                row.push_back( temp->val);      // if we get a node we push its value in row
                if( temp->left){                // then check for its childern and push them in queue
                    q.push(temp->left);
                }
                if( temp->right){
                    q.push(temp->right);
                }
            }
            
        }
        return arr;
                
        
    }
};