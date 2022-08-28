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
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if( !head){
            return head;
        }
        
        ListNode* tail = head;
        int length = 1;
        
        while( tail->next){
            tail = tail->next;
            length++;               // to get the length as well as tail of ll
        }
        
        k = k%length;               // to get the no of rotations if greater than len
        
        if( k == 0){
            return head;            // if k is multiple of length we return as it is
        }
        
        ListNode* cur = head;
        
        for( int i = 0 ; i < length - k -1 ; i++){
            cur = cur->next;        // iter to get the tail of new ll
        }
        
        ListNode* newHead = cur->next;  
        cur->next = NULL;           // setting null as end of new ll
        
        tail->next = head;          // connecting end of old ll to head
        
        return newHead;
        
        
    }
};