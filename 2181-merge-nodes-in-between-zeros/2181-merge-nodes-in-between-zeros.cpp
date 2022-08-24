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
    ListNode* mergeNodes(ListNode* head) {
        
        head = head->next;      // because head is 0 we know
        ListNode* cur = head; 
        
        int sum = 0;            // to store the sum of numbers between 0s
        
        ListNode* temp = head;
        

            while( temp ){
                
                sum += temp->val;
                temp= temp->next;
                
                if(temp && temp->val == 0){   
                    cur->val = sum;         // when we reach 0 the sum gets stored in 'stay behind cur node'
                    sum=0;
                    cur->next = temp->next; // cur is updated to the start of next chain of numbers and the nodes in between are skipped
                    cur= cur->next;
                }
                
            }
        
        return head;
    }
};