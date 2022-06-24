/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // step 1 ) make a hashmap with original nodes as key and duplicate nodes as values
        // step 2 ) original.duplicate ka random -> original.random.duplicate
        if(!head){
            return head;
        }
        unordered_map<Node*,Node*> map;
        
        Node* cur = head;
        Node* dupHead = new Node(cur->val);
        map[cur] = dupHead;
        
        while( cur->next){
            cur = cur->next;
            dupHead->next = new Node(cur->val);
            dupHead = dupHead->next;
            map[cur]= dupHead;
        }
        
        cur=head;
        
        while(cur){
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }        
        
        return map[head];
        
    }
};