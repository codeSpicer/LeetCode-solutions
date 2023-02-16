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
    
    int length( ListNode* head ){ 
        ListNode* cur = head;
        int count = 0;
        while( cur){
            count++;
            cur = cur->next;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        int len = length(head);
        
        if( k == 0 || len == 0){
            return head;
        }
        k = k%len;
        
        
        // 1 2 3 4 5 
            
        ListNode* cur = head;
        
        for( int i = 0 ; i < len - k -1 ;i++){
            cur = cur->next;
        }
        
        ListNode* end = cur;
        
        while( end->next){
            end = end->next;
        }
        
        end->next = head;
        end = cur;
        cur = cur->next;
        end->next = NULL;
        return cur;
        
    }
};