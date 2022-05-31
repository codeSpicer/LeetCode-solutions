/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if( !root){
            return NULL;
        }
        
        queue<Node*> q;     // we use a queue to do breadth first / level order traversal
        
        q.push(root);
        
        while( !q.empty() ){
            
            Node* rightnode = NULL;     // we make a right node NULL so that 
                                    //we can set the rightmost node's right node as null
            
            for( int i = size(q) ;i > 0 ; i--){     // to traverse all the nodes at one level
                Node* cur = q.front(); q.pop();
                
                cur->next = rightnode;     // we set the cur.next as rightnode for every node 
                rightnode = cur;           // make the cur node as rightnode
                        //so that the node left to the cur node can have next node as the current node                                      ( if you are reading this sorry and just brain)
                if( cur->right){
                    q.push(cur->right);     // push right node first very important 
                }
                if( cur->left){
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};