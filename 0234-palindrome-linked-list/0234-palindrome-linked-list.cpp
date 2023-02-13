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
    bool isPalindrome(ListNode* head) {
        
        ListNode* head2 = reverse( middle(head));
        
        while( head && head2){
            if( head->val != head2->val ){
                return false;
            }
            head = head->next;
            head2 = head2->next;
            
        }
        return true;
        
        
    }
    
    ListNode* middle( ListNode* head){
        ListNode* fast = head;
        ListNode* mid = head;
        
        while( fast && fast->next){
            fast = fast->next->next;
            mid = mid->next;
        }
        return mid;
    }
    
    ListNode* reverse( ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head;
        
        while( cur ){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
        
    }
    
};