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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if( !list1){
            return list2;
        }else if( !list2){
            return list1;
        }
        
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* placeholder = new ListNode(0);
        
        if( t1->val < t2->val ){
            placeholder->next = t1;
            t1 = t1->next;
        }else{
            placeholder->next = t2;
            t2 = t2->next;
        }
        
        ListNode* cur = placeholder->next;
        
        while( t1 && t2 ){
            
            if( t1->val < t2->val ){
                cur->next = t1;
                t1 = t1->next;
            }else{
                cur->next = t2;
                t2 = t2->next;
            }
            cur = cur->next;
        }
        
        if( t1){
            cur->next = t1;
        }
        if( t2){
            cur->next = t2;
        }
        
        return placeholder->next;
        
    }
};