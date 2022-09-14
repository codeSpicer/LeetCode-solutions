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
    bool found = false;
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        int t = k;
        
        treeToArr(root, arr , t);
        
        return arr[k-1];
        
    }
    
    void treeToArr( TreeNode* root ,  vector<int> &arr , int &t ){
        
        if( !root || found){
            return;
        }
        
        treeToArr( root->left , arr , t);
        arr.push_back(root->val);
        t--;
        if( t == 0){
            found = true;
        }
        treeToArr( root->right ,arr , t);
        
    }
};