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
    int pairSum(ListNode* head) {
        
        int ans = 0;
        
        ListNode* mid = head;
        ListNode* fast = head;
        
        while( fast && fast->next){
            fast = fast->next->next;
            mid = mid->next;
        }
        
        // reverse second half
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while( mid){
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        
        while(  prev){
            ans = max(ans , head->val + prev->val);
            head= head->next;
            prev = prev->next;
            
        }
        return ans;
    }
};