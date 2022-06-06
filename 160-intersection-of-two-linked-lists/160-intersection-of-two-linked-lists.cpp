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
        
        // first approach can be a double loop and compare nodes of first linked list one by one with each node of second linked list 
        //  time complexi -> O(n^2) space complexi will be constant because no extra memory
        
        // second would be to add all nodes of first linked list to a hashset
        // and iterate the second list to find the common node
        // time -> O(n+m) space -> O(n)
        
        unordered_set<ListNode*> set;
        
        while( headA){
            set.insert(headA);
            headA = headA->next;
        }
        
        while( headB){
            
            if( set.find(headB) != set.end()){
                return headB;
            }
            headB = headB->next;            
        }
        
        return NULL;
        
    }
};