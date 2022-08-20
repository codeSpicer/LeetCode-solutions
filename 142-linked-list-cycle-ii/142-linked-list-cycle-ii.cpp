/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* ans = NULL;
        bool cycle = false;
        
        while( fast && fast->next ){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if( slow == fast){
                fast = head;
                cycle = true;
                break;
            }
            
        }
        
        if( fast == head){
            while( slow != fast ){
                slow = slow->next;
                fast = fast->next;    
            }
        }
         
        if( !cycle){
            return NULL;
        }
        return fast;
        
    }
};