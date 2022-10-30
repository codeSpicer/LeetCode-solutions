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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* temp = head;
        
        for( int i = 1 ; i < k ; i++){
            temp = temp->next;
        }
        
        ListNode* first = temp;
        
        ListNode* second = head;
        
        temp= temp->next;
        while( temp){
            temp = temp->next;
            second = second->next;
        }
        
        swap( second->val , first->val);
        
        return head;
        
    }
};