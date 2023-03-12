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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if( lists.size() == 0){
            return NULL;
        }
        
        while( lists.size() > 1){
            
            vector<ListNode*> new_list;
            
            for( int i = 0 ; i < lists.size() ; i = i+2){
                ListNode* t1 = lists[i];
                ListNode* t2 = NULL;
                if( i+1 < lists.size() ){
                    t2 = lists[i+1];
                }
                new_list.push_back( merge(t1 , t2));
            }
            
            lists = new_list;
        }
        
        return lists[0];
        
        
    }
    
    ListNode* merge( ListNode* l1 , ListNode* l2){
        if( !l1){
            return l2;
        }
        if( !l2){
            return l1;
        }
        
        ListNode* head = new ListNode();
        ListNode* cur = head;
        
        while( l1 && l2){
            if( l1->val > l2->val ){
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }else{
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
        }
        if( l1){
            cur->next  = l1;
        }
        if( l2){
            cur->next = l2;
        }
        return head->next;
        
    }
};