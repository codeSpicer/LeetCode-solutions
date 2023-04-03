class Solution {
public:
    
    vector<int> findOrder(int N, vector<vector<int>>& prereq) {
        // apply kahn's algorithm 
        
        vector<vector<int>> g( N);
        vector<int> indegree( N);
        
        for( auto edge : prereq){
            g[edge[1]].push_back( edge[0]);         // adj list
        }       
        
        for( int i = 0 ;i < N ; i++){
            for( auto neigh : g[i]){
                indegree[neigh]++;                   // in degree array
            }
        }
        
        queue<int> q;
        
        for( int i = 0 ; i < N ;i++){
            if( indegree[i] == 0){
                q.push(i);                          // adding nodes with 0 in degree in array
            }
        }
        
        vector<int> result;
        
        while( !q.empty() ){
            
            int node = q.front();
            q.pop();
            
            for( auto i : g[node]){
                indegree[i]--;                      // because the node is taken in ans, we remove all its out degree
                if( indegree[i]== 0){
                    q.push(i);                      // if some node's in degree goes to 0 we add it to the q
                }
            }
            result.push_back( node);                
        }
        
        if( result.size() == N){                    // not a valid topo sort // cycle present
            return result;
        }
        
        return vector<int> {};
    }
};