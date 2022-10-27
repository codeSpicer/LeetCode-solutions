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
    ListNode* partition(ListNode* head, int x) {
        
        // thinking of breaking the list in 2 parts
        // we make a list of nodes less than x 
        // and list of nodes more than x
        
        // then attach them and return
        
        ListNode* temp = head;
        ListNode* less = new ListNode(0);   // dummy nodes
        ListNode* more = new ListNode(0);
        ListNode* ans = less;   
        ListNode* mid = more;
        
        
        while( temp ){
            
            if( temp->val < x){
                
                less->next = temp;
                less = less->next;
                
            }else{
                
                more->next = temp;
                more = more->next;
                
            }
            
            temp = temp->next;
            
        }        
        more->next = NULL;
        less->next = mid->next;
        
        
        return ans->next ;
        
    }
};