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
    void reorderList(ListNode* head) {
                // basic idea is to use a stack to store all nodes first
        // then in second iteration we link the first node to top element of stack
        // and top element of stack to secont element of list
        
        stack<ListNode*> st;
        ListNode* temp = head;
        
        while(temp){
            st.push(temp);
            temp= temp->next;
        }
        
        // 1 2 3 4 5 6 7 8 9 
        // 1 9 2 8 3 7 4 5 6
        temp = head;
        for( int i = 0 ; i< st.size() ; i++){
            
            st.top()->next = temp->next;
            temp->next = st.top();
            temp = st.top()->next;
            st.pop();
            
        }
        temp->next = NULL;
        
        head = temp;
        
    }
};