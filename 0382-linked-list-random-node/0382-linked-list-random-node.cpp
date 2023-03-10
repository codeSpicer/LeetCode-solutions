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
    int length;
    ListNode* list;
    Solution(ListNode* head) {
        length = len( head);
        list = head;
    }
    
    int getRandom() {
        int count = rand() % length ;
        ListNode* cur = list;
        for( int i = 0 ; i < count ; i++ ){
            cur= cur->next;
        }
        return cur->val;
    }
    
    int len( ListNode* head){
        ListNode* cur = head;
        int count = 0;
        while( cur){
            count++;
            cur= cur->next;
        }
        return count;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */