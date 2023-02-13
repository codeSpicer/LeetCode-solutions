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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        while( l1 || l2 || carry ){
            
            int x = l1? l1->val : 0;
            int y = l2? l2->val : 0;
            
            
            int sum = x+y+carry;
            carry = 0;
            if( sum > 9){
                carry = 1;
                sum %= 10;
            }
            
            cur->next = new ListNode( sum);
            cur = cur->next;
            
            if( l1){
                l1 = l1->next;
            }
            if( l2 ){
                l2 = l2->next;
            }
            
        }
        
        return head->next;
        
    }
};