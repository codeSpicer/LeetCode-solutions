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
    bool findTarget(TreeNode* root, int k) {
        
        // one approach that works for non bst also is to use a hashset to store the nodes values 
        // then search for the complement of that node in set
        
        // other approach is to make a sorted array from the bst
        // and then use 2 pointer approach to add up to target
        
        // unordered_set<int> set;
        // return dfs(root , set , k );
        
        vector<int> arr;
        inorder( root , arr);
        
        int i = 0; int j = arr.size()-1;
        
        while( i < j){
            if( arr[i]+arr[j] > k){
                j--;
            }else if(arr[i]+arr[j] < k){
                i++;
            }else if(arr[i]+arr[j] == k){
                return true;
            }
        }
        return false;
    }
    
    void inorder( TreeNode* root , vector<int> &arr){
        if( root == NULL){
            return ;
        }
        inorder( root->left , arr);
        arr.push_back(root->val);
        inorder(root->right , arr);
    }
    
    bool dfs( TreeNode* root , unordered_set<int> &set , int k){         // set pass karte hue & laga dena :)
        
        if( root == NULL){return false;}
        
        if( set.count(k - root->val)){return true;}
        
        set.insert(root->val);
        
        return dfs(root->left , set, k) || dfs( root->right , set , k);       
    }
    
};
