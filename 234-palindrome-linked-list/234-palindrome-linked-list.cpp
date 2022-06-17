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
        // approach 0 use a array to store values of linked list
        // approach 1 use a stack and compare
        // approach 2 reverse half of the linked list and use 2 pointer approach
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while( fast && fast->next){     // finding middle
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* prev=NULL;
        ListNode* temp=slow;
        while( slow){                   // reversing the second half of linked list
            temp= temp->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        
        // now prev has right end of ll and head has left end of ll
        while( prev){
            if( prev->val != head->val){        // iterate using 2 pointers from both end
                return false;
            }
            prev = prev->next;
            head= head->next;
        }
        
        return true;
    }
    

};