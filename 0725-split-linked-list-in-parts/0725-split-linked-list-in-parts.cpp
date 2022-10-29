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
    
    int list_length( ListNode* head ){
        ListNode* temp = head;
        int len = 0;
        while( temp ){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        // we can divide the length of list with k to find the number or parts 
        // and to properly fill node we can let the first len%k nodes carry one extra node
        
        vector<ListNode*> result;
        
        int len = list_length(head);    // no of nodes in list
        
        int nodes_per_list = len / k;   
        int extra = len % k;
        
        ListNode* cur = head;
        
        for( int i = 0 ; i < k ; i++){
            
            head = cur;     // head will store the start of small linkedlist
            
            for( int j = 0 ; j < nodes_per_list + ( i < extra ) -1 ; j++){
                
                if( cur ){
                    cur = cur->next;
                }
                
            }
            
            if( cur ){
                ListNode* prev = cur;
                cur = cur->next;
                prev->next = NULL;
            }
            
            result.push_back(head);
            
        }        
        
        return result;        
        
    }
};