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
        
        // checks to see if any list is empty
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
        ListNode* placeholder;      // node which we return
        
        if( ptr1->val <= ptr2->val){    // choosing the head node by comparing the elements of 2 lists
            ans = ptr1;
            ptr1 = ptr1->next;
        }else{
            ans = ptr2;
            ptr2 = ptr2->next;
        }
        placeholder = ans;              // storing the pos. of head node
        
        while( ptr1 && ptr2){           // while any one list has not ended we go on comparing
                                        // the elements and attaching them to the end of the list 
            
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
    
        // once any of the 2 lists finish we just attach the other list to the end of out answer list
        
        if( ptr1){
            ans->next = ptr1;
        }
        if( ptr2){
            ans->next = ptr2;
        }
        
        return placeholder;
    }
};