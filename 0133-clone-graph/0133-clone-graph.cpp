/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int , Node*> vis;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if( vis.count(node->val)) return vis[node->val];
        
        Node* cur = new Node( node->val);
        
        vis[node->val] = cur;
        
        for( auto n : node->neighbors){
            Node* neigh_node = cloneGraph(n);
            cur->neighbors.push_back(neigh_node);
        }
        
        return cur;
    }
};
