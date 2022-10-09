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
    ListNode* oddEvenList(ListNode* head) {
        
        if( !head ){ return NULL;}
        
        ListNode* odd = head;
        ListNode* oddPrev;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
//         while( odd && odd->next){
//             odd->next = odd->next->next;
//             oddPrev = odd;
//             odd = odd->next;
//         }
        
//         while( even && even->next){
//             even->next = even->next->next;
//             even = even->next;
//         }
        while(  even && even->next ){                   // to keep in mind odd and even should be moved forward together else the links will be broken for the other to traverse
            odd->next = odd->next->next;
            even->next = even->next->next;
            oddPrev = odd;
            odd = odd->next;
            even = even->next;
        }
        
        if( odd){
            odd->next = evenHead;
        }else{
            oddPrev->next = evenHead;
        }
        
        return head;
        
        
    }
};


// []
// [1]
// [1,2]
// [1,2,3]
// [1,2,3,4]
// [1,2,3,4,5]
// [1,2,3,4,5,6]