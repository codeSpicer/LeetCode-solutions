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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // we iterate both linked list from start
        // when the ptr of one linked list reaches the end we make it the ptr of other linked list
        // what it does is , till the time the longer linked list covers the diffrence in lenght of 
        // smaller linked list we make the smaller linked list cover longer linked list from start
        // then when longer linked list is traversed we move its pointer to smaller linked lists head
        // then thwy both are at same distance from end and  , we can just look for the coinciding node
        
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while( ptr1 != ptr2){
            if(ptr1 == NULL){
				ptr1 = headB;
			}
			else{
				ptr1 = ptr1 -> next;
			}
			if(ptr2 == NULL){
				ptr2 = headA;
			}
			else{
				ptr2 = ptr2 -> next;
			}
            
        }
        
        return ptr1;
        
    }
};