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
    ListNode* sortList(ListNode* &head) {
        
        // we use merge sort to solve in o( nlog n) time
        
        // step one is to split the list in 2 parts till there is only one node left in every list
        
        // step two is to combine the linked list like we did int merge two sorted linked lists
        
        // space complexity will be o( log n ) because at the max depth we will be log n deep
        
        if( !head || !head->next){
            return head;
        }
        
        ListNode* mid = findMid( head);
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(mid);
        
        return merge( h1 , h2);
        
    }
    
    ListNode* findMid( ListNode* &head){
        
        ListNode* temp = head;
        ListNode* mid = head;
        ListNode* prev = NULL;
        
        while( temp && temp->next){
            temp = temp->next->next;
            prev = mid;
            mid = mid->next;
        }
        if( prev){
            prev->next = NULL;
        }
        return mid;
    }
    
    ListNode* merge( ListNode* &h1 , ListNode* &h2){
        
        if( !h1 && !h2){
            return NULL;
        }else if( !h2){
            return h1;
        }else if( !h1){
            return h2;
        }
        
        ListNode* ans = NULL;
        ListNode* temp= NULL;
        
        if( h1->val < h2->val){
            temp = h1;
            h1 = h1->next;
        }else{
            temp  = h2;
            h2 = h2->next;
        }
        
        ans = temp;
        
        while( h1 && h2){
            
            if( h1->val < h2->val ){
                temp->next = h1;
                h1 = h1->next;
            }else{
                temp->next  = h2;
                h2 = h2->next;
            }
            temp= temp->next;
        }
        
        if( h1){
            temp->next = h1;
        }
        if( h2){
            temp->next = h2;
        }
        
        return ans;
        
    }
    
};