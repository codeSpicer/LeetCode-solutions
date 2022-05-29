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
        
        if( !list1 && !list2){
            return NULL;
        }else if( !list1){
            return list2;
        }else if( !list2){
            return list1;
        }
        
        
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* ans;
        ListNode* placeholder;
        
        if( ptr1->val <= ptr2->val){
            ans = ptr1;
            ptr1 = ptr1->next;
        }else{
            ans = ptr2;
            ptr2 = ptr2->next;
        }
        placeholder = ans;
        
        while( ptr1 && ptr2){
            
            if( ptr1->val <= ptr2->val ){
                ans->next = ptr1;
                ans = ans->next;
                ptr1 = ptr1->next;
            }else{
                ans->next = ptr2;
                ans = ans->next;
                ptr2 = ptr2->next;
            }
            
        }
        
        while( ptr1 ){
            ans->next = ptr1;
            ptr1 = ptr1->next;
            ans = ans->next;
        }        
        while( ptr2 ){
            ans->next = ptr2;
            ptr2 = ptr2->next;
            ans = ans->next;
        }
        
        return placeholder;
    }
};