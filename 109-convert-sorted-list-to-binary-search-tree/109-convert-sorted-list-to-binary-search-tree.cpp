/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        // idea is to find the middle of the linked list make it root of tree then make the next node of mid node as head 2 then pass the 2 diff lists in the function recursively
        
        if( !head){
            return NULL;
        }
        if( !head->next){
            return new TreeNode(head->val);
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        
        while( fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;                      // breaks the list in 2 parts so we can pass separate lists 
        
        TreeNode* root = new TreeNode(slow->val);// makes the middle node root   
        
        root->left = sortedListToBST(head);         // first half as left child 
        root->right = sortedListToBST(slow->next);  // second half as right child
        
        return root;
        
    }
};